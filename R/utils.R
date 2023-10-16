stopf <- function(fmt, ...) {
  stop(sprintf(fmt, ...), call. = FALSE)
}
