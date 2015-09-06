# SML, String Mathematical Librairy

SML is a little librairy to do some calculations with strings. There is no limit with the size of the number contains in the string.

## Functions

* `int sml_add(const char *op1, const char *op2, char *dest);`  
Add `op1` and `op2` (`dest` is the result).
* `int sml_sub(const char *op1, const char *op2, char *dest);`  
Subtract `op1` and `op2` (`dest` is the result).
* `int sml_mul(const char *op1, const char *op2, char *dest);`  
Multiply `op1` and `op2` (`dest` is the result).
* `int sml_div(const char *op1, const unsigned long long op2, char *dest, unsigned long long *rest);`  
Divide `op1` and `op2` (`dest` is the result and `rest` the remainder).

## To do

* Implement decimal operations.
* Implement related operations.
* Create functions wich reallocate the strings by size.

## See also

* [GMP](https://gmplib.org/), GNU Project
* [Numerus](https://github.com/LeMagnesium/numerus), by @LeMagnesium
