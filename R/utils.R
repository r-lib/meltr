# Silence R CMD check note
#' @importFrom tibble tibble
NULL

is.connection <- function(x) inherits(x, "connection")

`%||%` <- function(a, b) if (is.null(a)) b else a

#' Determine whether progress bars should be shown
#'
#' Progress bars are shown _unless_ one of the following is `TRUE`
#' - The bar is explicitly disabled by setting `options(readr.show_progress = FALSE)`
#' - The code is run in a non-interactive session (`interactive()` is `FALSE`).
#' - The code is run in an RStudio notebook chunk.
#' - The code is run by knitr / rmarkdown.
#'
#' @return A logical value
#' @export
#' @examples
#' show_progress()
show_progress <- function() {
  isTRUE(getOption("readr.show_progress")) && # user disables progress bar
    interactive() && # an interactive session
    !isTRUE(getOption("rstudio.notebook.executing")) && # Not running in an RStudio notebook chunk
    !isTRUE(getOption("knitr.in.progress")) # Not actively knitting a document
}

#' @importFrom tibble as_tibble
#' @export
as_tibble.meltr_spec_tbl_df <- function(x, ...) {
  attr(x, "spec") <- NULL
  attr(x, "problems") <- NULL
  class(x) <- setdiff(class(x), "meltr_spec_tbl_df")
  NextMethod("as_tibble")
}

#' @export
as.data.frame.meltr_spec_tbl_df <- function(x, ...) {
  attr(x, "spec") <- NULL
  attr(x, "problems") <- NULL
  class(x) <- setdiff(class(x), "meltr_spec_tbl_df")
  NextMethod("as.data.frame")
}

#' @export
`[.meltr_spec_tbl_df` <- function(x, ...) {
  attr(x, "spec") <- NULL
  attr(x, "problems") <- NULL
  class(x) <- setdiff(class(x), "spec_tbl_df")
  NextMethod(`[`)
}

#' @importFrom methods setOldClass
setOldClass(c("meltr_spec_tbl_df", "tbl_df", "tbl", "data.frame"))

# @export
compare.meltr_spec_tbl_df <- function(x, y, ...) {
  attr(x, "spec") <- NULL
  attr(x, "problems") <- NULL

  attr(y, "spec") <- NULL
  attr(y, "problems") <- NULL

  NextMethod("compare")
}

# @export
compare_proxy.meltr_spec_tbl_df <- function(x) {
  attr(x, "spec") <- NULL
  attr(x, "problems") <- NULL
  x
}

is_named <- function(x) {
  nms <- names(x)

  if (is.null(nms)) {
    return(FALSE)
  }

  all(nms != "" & !is.na(nms))
}

.onLoad <- function(...) {
  register_s3_method("testthat", "compare", "meltr_spec_tbl_df")
  register_s3_method("waldo", "compare_proxy", "meltr_spec_tbl_df")
}

register_s3_method <- function(pkg, generic, class, fun = NULL) {
  stopifnot(is.character(pkg), length(pkg) == 1)
  stopifnot(is.character(generic), length(generic) == 1)
  stopifnot(is.character(class), length(class) == 1)

  if (is.null(fun)) {
    fun <- get(paste0(generic, ".", class), envir = parent.frame())
  } else {
    stopifnot(is.function(fun))
  }

  if (pkg %in% loadedNamespaces()) {
    registerS3method(generic, class, fun, envir = asNamespace(pkg))
  }

  # Always register hook in case package is later unloaded & reloaded
  setHook(
    packageEvent(pkg, "onLoad"),
    function(...) {
      registerS3method(generic, class, fun, envir = asNamespace(pkg))
    }
  )
}

# Silence R CMD check note
#  Namespaces in Imports field not imported from:
#    ‘R6’ ‘rlang’
#    All declared Imports should be used.
# See https://github.com/hadley/r-pkgs/issues/828
fake_function_1 <- function() R6::R6Class
fake_function_2 <- function() rlang::int
