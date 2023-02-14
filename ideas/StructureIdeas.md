# States

Sample 1: `main := () -> exit_code: int32 { exit_code = 169; };`

| Start state         | Next char | Next state          |     |
|---------------------|-----------|---------------------|-----|
| whitespace (init)   | m         | letters             | -   |
| letters             | ...       | letters             | -   |
| letters             |           | whitespace          | -   |
| whitespace          | :         | colon               | -   |
| colon               | =         | equals_branch       | -   |
| equals_branch       |           | whitespace          | -   |
| whitespace          | (         | open_parenthesis    | -   |
| open_parenthesis    | )         | close_parenthesis   | -   |
| close_parenthesis   |           | whitespace          | -   |
| whitespace          | -         | dash_branch         | -   |
| dash_branch         | >         | right_arrow         | -   |
| right_arrow         |           | whitespace          | -   |
| whitespace          | e         | letters             | -   |
| letters             | ...       | letters             | -   |
| letters             | :         | colon               | -   |
| colon               |           | whitespace          | -   |
| whitespace          | i         | letters             | -   |
| letters             | ...       | letters             | -   |
| letters             |           | whitespace          | -   |
| whitespace          | {         | open_curly_bracket  | -   |
| open_curly_bracket  |           | whitespace          | -   |
| whitespace          | e         | letters             | -   |
| letters             | ...       | letters             | -   |
| letters             |           | whitespace          | -   |
| whitespace          | =         | equals_branch       | -   |
| equals_branch       |           | whitespace          | -   |
| whitespace          | 1         | number_branch       | -   |
| number_branch       | ...       | number_branch       | -   |
| number_branch       | ;         | semicolon           | -   |
| semicolon           |           | whitespace          | -   |
| whitespace          | }         | close_curly_bracket | -   |
| close_curly_bracket | ;         | semicolon           | -   |
| semicolon           | (EOF)     | eof                 | -   |

| All states          |
|---------------------|
| close_curly_bracket |
| close_parenthesis   |
| colon               |
| dash_branch         |
| eof                 |
| equals_branch       |
| letters             |
| number_branch       |
| open_curly_bracket  |
| open_parenthesis    |
| right_arrow         |
| semicolon           |
| whitespace          |

| Present state transitions            | Effect                                               |
|--------------------------------------|------------------------------------------------------|
| close_curly_bracket > semicolon      | Store                                                |
| close_parenthesis > whitespace       | Store                                                |
| colon > equals_branch                | Store colon to buffer                                |
| colon > whitespace                   | Store                                                |
| dash_branch > right_arrow            | Nop                                                  |
| equals_branch > whitespace           | Store "="                                            |
| letters > colon                      | Store identifier or keyword                          |
| letters > letters                    | Continue storing chars to buffer or fail if too long |
| letters > whitespace                 | Store identifier or keyword                          |
| number_branch > number_branch        | Continue storing chars to buffer or fail if too long |
| number_branch > semicolon            | Store integer                                        |
| open_curly_bracket > whitespace      | Store                                                |
| open_parenthesis > close_parenthesis | Store                                                |
| right_arrow > whitespace             | Store "->"                                           |
| semicolon > eof                      | Store (end)                                          |
| semicolon > whitespace               | Store                                                |
| whitespace > close_curly_bracket     | Nop                                                  |
| whitespace > colon                   | Nop                                                  |
| whitespace > dash_branch             | Nop                                                  |
| whitespace > equals_branch           | Nop                                                  |
| whitespace > letters                 | Start storing chars to buffer                        |
| whitespace > number_branch           | Start storing chars to buffer                        |
| whitespace > open_curly_bracket      | Nop                                                  |
| whitespace > open_parenthesis        | Nop                                                  |


| All potential state transitions           | Effect                                                 |
|-------------------------------------------|--------------------------------------------------------|
| close_curly_bracket > close_curly_bracket | TBD, may not be possible with ;-semantics              |
| close_curly_bracket > close_parenthesis   | Store                                                  |
| close_curly_bracket > colon               | TBD, probably not possible                             |
| close_curly_bracket > dash_branch         | Maybe comment?                                         |
| close_curly_bracket > eof                 | Error                                                  |
| close_curly_bracket > equals_branch       | TBD, probably not possible                             |
| close_curly_bracket > letters             | TBD, probably not possible                             |
| close_curly_bracket > number_branch       | TBD, probably not possible                             |
| close_curly_bracket > open_curly_bracket  | TBD, probably not possible                             |
| close_curly_bracket > open_parenthesis    | TBD, probably not possible. Potentially a lambda call? |
| close_curly_bracket > semicolon           | Store                                                  |
| close_curly_bracket > whitespace          | Store                                                  |
| close_parenthesis > close_curly_bracket   | TBD, probably not possible                             |
| close_parenthesis > close_parenthesis     | Store                                                  |
| close_parenthesis > colon                 | TBD, probably possible                                 |
| close_parenthesis > dash_branch           | Store                                                  |
| close_parenthesis > eof                   | Error                                                  |
| close_parenthesis > equals_branch         | Store                                                  |
| close_parenthesis > letters               | TBD, probably not possible                             |
| close_parenthesis > number_branch         | TBD, probably not possible                             |
| close_parenthesis > open_curly_bracket    | Store                                                  |
| close_parenthesis > open_parenthesis      | TBD                                                    |
| close_parenthesis > semicolon             | Store                                                  |
| close_parenthesis > whitespace            | Store                                                  |
| colon > close_curly_bracket               | Error                                                  |
| colon > close_parenthesis                 | Error                                                  |
| colon > colon                             | Error                                                  |
| colon > dash_branch                       | Maybe comment?                                         |
| colon > eof                               | Error                                                  |
| colon > equals_branch                     | Store                                                  |
| colon > letters                           | Store                                                  |
| colon > number_branch                     | Store                                                  |
| colon > open_curly_bracket                | TBD, probably not possible                             |
| colon > open_parenthesis                  | Store                                                  |
| colon > semicolon                         | Error                                                  |
| colon > whitespace                        | Store                                                  |
| dash_branch > close_curly_bracket         | Error                                                  |
| dash_branch > close_parenthesis           | Error                                                  |
| dash_branch > colon                       | Error                                                  |
| dash_branch > eof                         | Error (Cannot end file with -)                         |
| dash_branch > letters                     | Store                                                  |
| dash_branch > number_branch               | Store                                                  |
| dash_branch > open_curly_bracket          | Error                                                  |
| dash_branch > open_parenthesis            |                                                        |
| dash_branch > right_arrow                 |                                                        |
| dash_branch > semicolon                   |                                                        |
| dash_branch > whitespace                  |                                                        |
| equals_branch > close_curly_bracket       |                                                        |
| equals_branch > close_parenthesis         |                                                        |
| equals_branch > colon                     |                                                        |
| equals_branch > dash_branch               |                                                        |
| equals_branch > eof                       |                                                        |
| equals_branch > equals_branch             |                                                        |
| equals_branch > letters                   |                                                        |
| equals_branch > number_branch             |                                                        |
| equals_branch > open_curly_bracket        |                                                        |
| equals_branch > open_parenthesis          |                                                        |
| equals_branch > right_arrow               |                                                        |
| equals_branch > semicolon                 |                                                        |
| equals_branch > whitespace                |                                                        |
| letters > close_curly_bracket             |                                                        |
| letters > close_parenthesis               |                                                        |
| letters > colon                           |                                                        |
| letters > dash_branch                     |                                                        |
| letters > eof                             |                                                        |
| letters > equals_branch                   |                                                        |
| letters > letters                         |                                                        |
| letters > number_branch                   |                                                        |
| letters > open_curly_bracket              |                                                        |
| letters > open_parenthesis                |                                                        |
| letters > right_arrow                     |                                                        |
| letters > semicolon                       |                                                        |
| letters > whitespace                      |                                                        |
| number_branch > close_curly_bracket       |                                                        |
| number_branch > close_parenthesis         |                                                        |
| number_branch > colon                     |                                                        |
| number_branch > dash_branch               |                                                        |
| number_branch > eof                       |                                                        |
| number_branch > equals_branch             |                                                        |
| number_branch > letters                   |                                                        |
| number_branch > number_branch             |                                                        |
| number_branch > open_curly_bracket        |                                                        |
| number_branch > open_parenthesis          |                                                        |
| number_branch > right_arrow               |                                                        |
| number_branch > semicolon                 |                                                        |
| number_branch > whitespace                |                                                        |
| open_curly_bracket > close_curly_bracket  |                                                        |
| open_curly_bracket > close_parenthesis    |                                                        |
| open_curly_bracket > colon                |                                                        |
| open_curly_bracket > dash_branch          |                                                        |
| open_curly_bracket > eof                  |                                                        |
| open_curly_bracket > equals_branch        |                                                        |
| open_curly_bracket > letters              |                                                        |
| open_curly_bracket > number_branch        |                                                        |
| open_curly_bracket > open_curly_bracket   |                                                        |
| open_curly_bracket > open_parenthesis     |                                                        |
| open_curly_bracket > right_arrow          |                                                        |
| open_curly_bracket > semicolon            |                                                        |
| open_curly_bracket > whitespace           |                                                        |
| open_parenthesis > close_curly_bracket    |                                                        |
| open_parenthesis > close_parenthesis      |                                                        |
| open_parenthesis > colon                  |                                                        |
| open_parenthesis > dash_branch            |                                                        |
| open_parenthesis > eof                    |                                                        |
| open_parenthesis > equals_branch          |                                                        |
| open_parenthesis > letters                |                                                        |
| open_parenthesis > number_branch          |                                                        |
| open_parenthesis > open_curly_bracket     |                                                        |
| open_parenthesis > open_parenthesis       |                                                        |
| open_parenthesis > right_arrow            |                                                        |
| open_parenthesis > semicolon              |                                                        |
| open_parenthesis > whitespace             |                                                        |
| right_arrow > close_curly_bracket         |                                                        |
| right_arrow > close_parenthesis           |                                                        |
| right_arrow > colon                       |                                                        |
| right_arrow > dash_branch                 |                                                        |
| right_arrow > eof                         |                                                        |
| right_arrow > equals_branch               |                                                        |
| right_arrow > letters                     |                                                        |
| right_arrow > number_branch               |                                                        |
| right_arrow > open_curly_bracket          |                                                        |
| right_arrow > open_parenthesis            |                                                        |
| right_arrow > right_arrow                 |                                                        |
| right_arrow > semicolon                   |                                                        |
| right_arrow > whitespace                  |                                                        |
| semicolon > close_curly_bracket           |                                                        |
| semicolon > close_parenthesis             |                                                        |
| semicolon > colon                         |                                                        |
| semicolon > dash_branch                   |                                                        |
| semicolon > eof                           |                                                        |
| semicolon > equals_branch                 |                                                        |
| semicolon > letters                       |                                                        |
| semicolon > number_branch                 |                                                        |
| semicolon > open_curly_bracket            |                                                        |
| semicolon > open_parenthesis              |                                                        |
| semicolon > right_arrow                   |                                                        |
| semicolon > semicolon                     |                                                        |
| semicolon > whitespace                    |                                                        |
| whitespace > close_curly_bracket          |                                                        |
| whitespace > close_parenthesis            |                                                        |
| whitespace > colon                        |                                                        |
| whitespace > dash_branch                  |                                                        |
| whitespace > eof                          |                                                        |
| whitespace > equals_branch                |                                                        |
| whitespace > letters                      |                                                        |
| whitespace > number_branch                |                                                        |
| whitespace > open_curly_bracket           |                                                        |
| whitespace > open_parenthesis             |                                                        |
| whitespace > right_arrow                  |                                                        |
| whitespace > semicolon                    |                                                        |
| whitespace > whitespace                   |                                                        |


# Ideas

Context should own the buffer, not the states themselves


