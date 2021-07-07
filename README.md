# meltr

<!-- badges: start -->
[![R-CMD-check](https://github.com/jimhester/meltr/workflows/R-CMD-check/badge.svg)](https://github.com/jimhester/meltr/actions)
<!-- badges: end -->

The goal of meltr is to ...

## Installation

You can install the released version of meltr from [CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("meltr")
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(meltr)
melt_csv(readr_example("mtcars.csv"))
melt_csv(readr_example("mtcars.csv.zip"))
melt_csv(readr_example("mtcars.csv.bz2"))

# Or directly from a string (must contain a newline)
melt_csv("x,y\n1,2\n3,4")

# To import empty cells as 'empty' rather than `NA`
melt_csv("x,y\n,NA,\"\",''", na = "NA")

# File types ----------------------------------------------------------------
melt_csv("a,b\n1.0,2.0")
melt_csv2("a;b\n1,0;2,0")
melt_tsv("a\tb\n1.0\t2.0")
melt_delim("a|b\n1.0|2.0", delim = "|")
```
