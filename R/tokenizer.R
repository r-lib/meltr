#' Tokenizers.
#'
#' Explicitly create tokenizer objects. Usually you will not call these
#' function, but will instead use one of the use friendly wrappers like
#' [readr::read_csv()].
#'
#' @keywords internal
#' @name Tokenizers
#' @examples
#' tokenizer_csv()
NULL

#' @export
#' @rdname Tokenizers
#' @param comment A string used to identify comments. Any text after the
#'   comment characters will be silently ignored.
#' @param na Character vector of strings to interpret as missing values. Set this
#'   option to `character()` to indicate no missing values.
#' @param quoted_na Should missing values inside quotes be treated as missing
#'   values (the default) or strings.
#' @param delim Single character used to separate fields within a record.
#' @param quote Single character used to quote strings.
#' @param trim_ws Should leading and trailing whitespace (ASCII spaces and tabs) be trimmed from
#'     each field before parsing it?
#' @param escape_double Does the file escape quotes by doubling them?
#'   i.e. If this option is `TRUE`, the value `""""` represents
#'   a single quote, `\"`.
#' @param escape_backslash Does the file use backslashes to escape special
#'   characters? This is more general than `escape_double` as backslashes
#'   can be used to escape the delimiter character, the quote character, or
#'   to add special characters like `\\n`.
#' @param skip_empty_rows Should blank rows be ignored altogether? i.e. If this
#'   option is `TRUE` then blank rows will not be represented at all.  If it is
#'   `FALSE` then they will be represented by `NA` values in all the columns.
#' @return A tokeenizer object
#' @examples
#' tokenizer_delim(",")
tokenizer_delim <- function(delim, quote = '"', na = "NA", quoted_na = TRUE, comment = "",
                            trim_ws = TRUE,
                            escape_double = TRUE,
                            escape_backslash = FALSE,
                            skip_empty_rows = TRUE) {
  structure(
    list(
      delim = delim,
      quote = quote,
      na = na,
      quoted_na = quoted_na,
      comment = comment,
      trim_ws = trim_ws,
      escape_double = escape_double,
      escape_backslash = escape_backslash,
      skip_empty_rows = skip_empty_rows
    ),
    class = "tokenizer_delim"
  )
}

#' @export
#' @rdname Tokenizers
tokenizer_csv <- function(na = "NA", quoted_na = TRUE, quote = "\"",
                          comment = "", trim_ws = TRUE,
                          skip_empty_rows = TRUE) {
  tokenizer_delim(
    delim = ",",
    na = na,
    quoted_na = quoted_na,
    quote = quote,
    comment = comment,
    trim_ws = trim_ws,
    escape_double = TRUE,
    escape_backslash = FALSE,
    skip_empty_rows = skip_empty_rows
  )
}

#' @export
#' @rdname Tokenizers
tokenizer_tsv <- function(na = "NA", quoted_na = TRUE, quote = "\"",
                          comment = "", trim_ws = TRUE,
                          skip_empty_rows = TRUE) {
  tokenizer_delim(
    delim = "\t",
    na = na,
    quoted_na = quoted_na,
    quote = quote,
    comment = comment,
    trim_ws = trim_ws,
    escape_double = TRUE,
    escape_backslash = FALSE,
    skip_empty_rows = skip_empty_rows
  )
}

#' @export
#' @rdname Tokenizers
tokenizer_line <- function(na = character(), skip_empty_rows = TRUE) {
  structure(list(na = na, skip_empty_rows = skip_empty_rows),
    class = "tokenizer_line"
  )
}

#' @export
#' @rdname Tokenizers
tokenizer_log <- function(trim_ws) {
  structure(list(trim_ws = trim_ws), class = "tokenizer_log")
}


#' @export
#' @rdname Tokenizers
#' @param begin,end Begin and end offsets for each file. These are C++
#'   offsets so the first column is column zero, and the ranges are
#'   [begin, end) (i.e inclusive-exclusive).
tokenizer_fwf <- function(begin, end, na = "NA", comment = "", trim_ws = TRUE,
                          skip_empty_rows = TRUE) {
  structure(list(
    begin = as.integer(begin), end = as.integer(end), na = na, comment = comment,
    trim_ws = trim_ws, skip_empty_rows = skip_empty_rows
  ),
  class = "tokenizer_fwf"
  )
}

#' @export
#' @rdname Tokenizers
tokenizer_ws <- function(na = "NA", comment = "", skip_empty_rows = TRUE) {
  structure(list(na = na, comment = comment, skip_empty_rows = skip_empty_rows),
    class = "tokenizer_ws"
  )
}
