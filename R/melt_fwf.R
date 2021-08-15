

#' Return melted data for each token in a fixed width file
#'
#' For certain non-rectangular data formats, it can be useful to parse the data
#' into a melted format where each row represents a single token.
#'
#' `melt_fwf()` parses each token of a fixed width file into a single row, but
#' it still requires that each field is in the same in every row of the
#' source file.
#'
#' @seealso [melt_table()] to melt fixed width files where each
#'   column is separated by whitespace, and [melt_fwf()] for the conventional
#'   way to read rectangular data from fixed width files.
#' @inheritParams readr::read_fwf
#' @param col_positions Column positions, as created by [fwf_empty()],
#'   [fwf_widths()] or [fwf_positions()]. To read in only selected fields,
#'   use [fwf_positions()]. If the width of the last column is variable (a
#'   ragged fwf file), supply the last end position as NA.
#' @return A [tibble()] of four columns:
#'   * `row`, the row that the token comes from in the original file
#'   * `col`, the column that the token comes from in the original file
#'   * `data_type`, the data type of the token, e.g. `"integer"`, `"character"`,
#'     `"date"`, guessed in a similar way to the `guess_parser()` function.
#'   * `value`, the token itself as a character string, unchanged from its
#'     representation in the original file.
#'
#'   If there are parsing problems, a warning tells you
#'   how many, and you can retrieve the details with [problems()].
#' @export
#' @examples
#' fwf_sample <- meltr_example("fwf-sample.txt")
#' writeLines(readLines(fwf_sample))
#'
#' # You can specify column positions in several ways:
#' # 1. Guess based on position of empty columns
#' melt_fwf(fwf_sample, fwf_empty(fwf_sample, col_names = c("first", "last", "state", "ssn")))
#' # 2. A vector of field widths
#' melt_fwf(fwf_sample, fwf_widths(c(20, 10, 12), c("name", "state", "ssn")))
#' # 3. Paired vectors of start and end positions
#' melt_fwf(fwf_sample, fwf_positions(c(1, 30), c(10, 42), c("name", "ssn")))
#' # 4. Named arguments with start and end positions
#' melt_fwf(fwf_sample, fwf_cols(name = c(1, 10), ssn = c(30, 42)))
#' # 5. Named arguments with column widths
#' melt_fwf(fwf_sample, fwf_cols(name = 20, state = 10, ssn = 12))
melt_fwf <- function(file, col_positions,
                     locale = default_locale(), na = c("", "NA"),
                     comment = "", trim_ws = TRUE, skip = 0, n_max = Inf,
                     progress = show_progress(),
                     skip_empty_rows = FALSE) {
  ds <- datasource(file, skip = skip, skip_empty_rows = skip_empty_rows)
  if (inherits(ds, "source_file") && empty_file(file)) {
    return(tibble::tibble(
      row = double(), col = double(),
      data_type = character(), value = character()
    ))
  }
  tokenizer <- tokenizer_fwf(as.integer(col_positions$begin), as.integer(col_positions$end),
    na = na,
    comment = comment, trim_ws = trim_ws,
    skip_empty_rows = skip_empty_rows
  )
  out <- melt_tokens(ds, tokenizer,
    locale_ = locale,
    n_max = if (n_max == Inf) -1 else n_max, progress = progress
  )
  warn_problems(out)
}

#' @rdname melt_fwf
#' @export
#' @param n Number of lines the tokenizer will read to determine file structure. By default
#'      it is set to 100.
fwf_empty <- function(file, skip = 0, skip_empty_rows = FALSE, col_names = NULL, comment = "", n = 100L) {
  ds <- datasource(file, skip = skip, skip_empty_rows = skip_empty_rows)

  out <- whitespaceColumns(ds, comment = comment, n = n)
  out$end[length(out$end)] <- NA

  col_names <- fwf_col_names(col_names, length(out$begin))
  out$col_names <- col_names
  out
}

#' @rdname melt_fwf
#' @export
#' @param widths Width of each field. Use NA as width of last field when
#'    reading a ragged fwf file.
#' @param col_names Either NULL, or a character vector column names.
fwf_widths <- function(widths, col_names = NULL) {
  pos <- cumsum(c(1L, abs(widths)))
  fwf_positions(pos[-length(pos)], pos[-1] - 1L, col_names)
}

#' @rdname melt_fwf
#' @export
#' @param start,end Starting and ending (inclusive) positions of each field.
#'    Use NA as last end field when reading a ragged fwf file.
fwf_positions <- function(start, end = NULL, col_names = NULL) {
  stopifnot(length(start) == length(end))
  col_names <- fwf_col_names(col_names, length(start))

  tibble(
    begin = start - 1L,
    end = end, # -1 to change to 0 offset, +1 to be exclusive,
    col_names = as.character(col_names)
  )
}


#' @rdname melt_fwf
#' @export
#' @param ... If the first element is a data frame,
#'   then it must have all numeric columns and either one or two rows.
#'   The column names are the variable names. The column values are the
#'   variable widths if a length one vector, and if length two, variable start and end
#'   positions. The elements of `...` are used to construct a data frame
#'   with or or two rows as above.
fwf_cols <- function(...) {
  x <- lapply(list(...), as.integer)
  names(x) <- fwf_col_names(names(x), length(x))
  x <- tibble::as_tibble(x)
  if (nrow(x) == 2) {
    res <- fwf_positions(as.integer(x[1, ]), as.integer(x[2, ]), names(x))
  } else if (nrow(x) == 1) {
    res <- fwf_widths(as.integer(x[1, ]), names(x))
  } else {
    stop("All variables must have either one (width) two (start, end) values.",
      call. = FALSE
    )
  }
  res
}

fwf_col_names <- function(nm, n) {
  nm <- nm %||% rep("", n)
  nm_empty <- (nm == "")
  nm[nm_empty] <- paste0("X", seq_len(n))[nm_empty]
  nm
}
