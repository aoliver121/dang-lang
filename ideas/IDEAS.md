`^` means exponent

`/%` is the divmod operator. Returns a structure with remainder and division result.

`=` (assignment) has no return value. No `a = b = c;` or `if a = 1 { ... };` or `my_func(param1 = 2);`

`--` is a one-line comment. Multi-line TBD, but I just thought of `--[ this is a comment ]--`

Built in arrays are always prefixed with the end position or length of the array. Multi-dimensional arrays are prefixed 
with either the dimensions or the end of the total array and n-1 dimension sizes.

Pointers are replaced with "references". References hide their validity behind a pseudo member variable `valid` rather 
than being equal to `nullptr` for example.

Literals have no size-associated type until assignment to one is forced. So `1` has no fixed bit-width, but 
`int32.from(1)` would have 32 bits. Similarly for string and float literals. Operations on literals 
`(7 + 12) / (10 - 0.5)` are only type evaluated when assigned to a sized type as well. We could either evaluate the 
expression analytically `i.e. int32.from((7 + 12) / (10 - 0.5)) -> int32.from(19 / 9.5) -> int32.from(2)`, or cast each 
individual literal first `i.e. (int32.from(7) + int32.from(12)) / (int32.from(10) - int32.from(0.5)) -> int32.from(19) 
/ int32.from(10) -> int32.from(1)`. Preferably the former.

Result types are built in and have similar pseudo member syntax to references, but instead of `valid`, it's something 
like `succ`, or `error`. For an arithmetic type, the type wrapped 
in a result can still perform the arithmetic operations. `e.g. x : int32 = possibly_zero(); y : int32.res = 10 / x; z : 
int32.res = y + 300;`. 

TODO binary stuff
