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
init - startsWithChar - wsSeq - : - = - wsSeq - ( - ) - wsSeq 
- { - wsSeq - startsWithChar - ( - " - unfilteredStr - " - ) 
- ; - wsSeq - } - ; - EOF
```