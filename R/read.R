#' @include utils.R

#' @export
read_ini <- function(file_name) {
  file_path <- normalizePath(file_name, mustWork = FALSE)
  if (!file.exists(file_path)) {
    stopf("Unable to file name %s", file_name)
  }
  rcpp_mini_reader(file_path)
}
