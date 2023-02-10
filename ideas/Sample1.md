# Sample 1

## Text

`main := () -> exit_code: int32 { exit_code = 169; };`

## Tokens

| Token content | Type                  |
|---------------|-----------------------|
| `main`        | identifier            |
| `:`           | colon                 |
| `=`           | equals                |
| `(`           | open_parenthesis      |
| `)`           | close_parenthesis     |
| `->`          | right_arrow           |
| `exit_code`   | identifier            |
| `:`           | colon                 |
| `int32`       | identifier or keyword |
| `{`           | open_curly_bracket    |
| `exit_code`   | identifier            |
| `=`           | equals                |
| `169`         | integer_literal       |
| `;`           | semicolon             |
| `}`           | close_curly_bracket   |
| `;`           | semicolon             |

## AST

```
top_level(defn(
    name(id("main")),
    type(none),
    value(func(
        inputs(none),
        outputs(decl(
            name(id("exit_code")),
            type(id("int32"))
        )),
        contents(asmt(
            to(id("exit_code")),
            from(int("169"))
        ))
    ))
))
```

## AST level possibilities

```
top_level << defn

defn.name << id
defn.type << none
defn.value << func

func.inputs << none
func.outputs << decl
func.contents << asmt

decl.name << id
decl.type << id

asmt.to << id
asmt.from << int
```
