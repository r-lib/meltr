#' Get path to meltr example
#'
#' meltr comes bundled with a number of sample files in its `inst/extdata`
#' directory. This function make them easy to access
#'
#' @param file Name of file. If `NULL`, the example files will be listed.
#' @return A file path or a vector of file names
#' @export
#' @examples
#' meltr_example()
#' meltr_example("mtcars.csv")
meltr_example <- function(file = NULL) {
  if (is.null(file)) {
    dir(system.file("extdata", package = "meltr"))
  } else {
    system.file("extdata", file, package = "meltr", mustWork = TRUE)
  }
}
