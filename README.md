
<!-- README.md is generated from README.Rmd. Please edit that file -->

# meltr

<!-- badges: start -->

[![R-CMD-check](https://github.com/jimhester/meltr/workflows/R-CMD-check/badge.svg)](https://github.com/jimhester/meltr/actions)
<!-- badges: end -->

<p align="center">
<img src="https://nacnudus.github.io/duncangarmonsway/posts/2018-12-29-meltcsv/im_melting_wicked_witch_of_the_west.jpg" alt="The wicked witch of the west saying 'I'm Melting, Melting!!!!!'">
</p>

The goal of ‘meltr’ is to provide a fast and friendly way to read
non-rectangular data (like ragged forms of ‘csv’, ‘tsv’, and ‘fwf’).

Standard tools like readr::read\_csv() can cope to some extent with
unusual inputs, like files with empty rows or newlines embedded in
strings. But some files are so wacky that standard tools don’t work at
all, and instead you have to take the file to pieces and reassemble it
in a standard design.

The meltr package separates delimited text files into individual cells.

## Installation

You can install the released version of meltr from
[CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("meltr")
```

## The problem with non-rectangular data

Here’s a contrived example that breaks two assumptions made by common
tools like `readr::read_csv()`.

1.  There are more cells in some rows than others.
2.  There are mixed data types within each column.

The `melt_csv()` function reads the file one cell at a time, importing
each cell of the file into a whole row of the final data frame.

``` r
writeLines("Help,,007,I'm
1960-09-30,FALSE,trapped in,7,1.21
non-rectangular,data,NA", "messy.csv")

library(meltr)

melt_csv("messy.csv")
#> # A tibble: 12 x 4
#>      row   col data_type value          
#>    <dbl> <dbl> <chr>     <chr>          
#>  1     1     1 character Help           
#>  2     1     2 missing   <NA>           
#>  3     1     3 character 007            
#>  4     1     4 character I'm            
#>  5     2     1 date      1960-09-30     
#>  6     2     2 logical   FALSE          
#>  7     2     3 character trapped in     
#>  8     2     4 integer   7              
#>  9     2     5 double    1.21           
#> 10     3     1 character non-rectangular
#> 11     3     2 character data           
#> 12     3     3 missing   <NA>
```

What the `melt_csv()` output means:

-   The output of `melt_csv()` is a data frame – structured data about
    un-structured data!
-   Each row of the data frame represents one cell of the input data.
-   The empty cell of row 1 is imported, but the missing cells at the
    ends of rows 1 and 3 aren’t.
-   No data type conversion is attempted – every value is imported as a
    string, and the `data_type` column merely gives meltr’s best guess
    of what the data types ought to be.

How can you use this? To begin with, you can do some simple
manipulations with ordinary functions.

For example you could extract the words.

``` r
library(dplyr)
#> 
#> Attaching package: 'dplyr'
#> The following objects are masked from 'package:stats':
#> 
#>     filter, lag
#> The following objects are masked from 'package:base':
#> 
#>     intersect, setdiff, setequal, union

data <- melt_csv("messy.csv") %>%
  filter(data_type == "character")
```

Or find if there are missing entries.

``` r
data %>%
  filter(data_type == "character")
#> # A tibble: 6 x 4
#>     row   col data_type value          
#>   <dbl> <dbl> <chr>     <chr>          
#> 1     1     1 character Help           
#> 2     1     3 character 007            
#> 3     1     4 character I'm            
#> 4     2     3 character trapped in     
#> 5     3     1 character non-rectangular
#> 6     3     2 character data
```

``` r
unlink("messy.csv")
```
