# String Math Program

## Problem Definition

Input from the user should be of the form SOS, where S represents a string
and O represents a mathematical symbol. There should be no spaces between the
three parts (the two S’s and the O). A string should consist of from one to nine
lowercase letters. The mathematical symbol should be from the set + - / *. These
symbols correspond to their natural use in the C language: addition, subtraction,
division, and multiplication.

If the user inputs a string containing symbols outside the lowercase letters, or
if the string has more than nine characters, the program should report an error.
If the user inputs a mathematical symbol outside the expected set, the program
should report an error. If the input provided by the user is not of the form SOS—
for example, if it is only SO, or only S—then the program should report an error.
The error messages can be generic; they do not have to describe specifically what
the user did wrong.

If a grammatically correct input is entered, the program should convert the
two strings to integer arrays and perform the given operation on each cell independently.
The resulting array should then be converted back to a string, and
displayed to the user. 

This should continue until the user gives the
keyphrase to exit the program (the keyphrase is of your choosing, good choices
are “quit”, “end”, “exit”, etc.).

For example:

Input> wxy+bbb
wxy + bbb => yzY

If the two input strings are not the same length, then each output character
beyond the length of the shorter string should be a copy of the character from
the longer string. 

For example:

Input> xyz+a
xyz + a => yyz

Here are some additional examples to clarify all expected operations.
These do not necessarily encompass all checks for errors, or all the cases that need
to be tested.

| <b>Example input</b>  | <b>Correct output</b>   |
| --------------------- |:-----------------------:|
| abc-aa                | Aac                     |
| dog*cat               | loG                     |   
| turtle/frog           | caable                  |    
| Frog+turtle           | bad input               |
| bird/tiger            | BabDr                   |
| emu+zebra             | Erwra                   |


