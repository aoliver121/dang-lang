# Simple example 1

## DETAILS

```
1 file
entry: main
entry-sig: ()
```

## SRC

```
main := () {
    temp_built_in_print("Hello, World!");
};
```

## TOKENS

```
main
:
=
(
)
{
temp_built_in_print
(
"Hello, World!"
)
;
}
;
```

## STATE MACHINE

```
main := () {\n    temp_built_in_print("Hello, World!");\n};
^   ^^^^^^^^^     ^                  ^^^            ^^^^ ^^
init - starts_with_char - wsSeq - : - = - wsSeq - ( - ) - wsSeq 
- { - wsSeq - starts_with_char - ( - " - unfilteredStr - " - ) 
- ; - wsSeq - } - ; - EOF
```