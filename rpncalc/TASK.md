# RPN Calculator

[Reverse polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
is a simple mathematical notation. Its main principle is that operators are
placed *after* the operands, instead of between them.

For example, the expression `5 + 2` could be translated to RPN as `5 2 +`. More
complicated operations can also be encoded in RPN, such as `((5 + 2) * 3) / 8`
which would be `5 2 + 3 * 8 /`.

*Hint:* RPN is naturally suited to using the
[stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) data type, so
you may want to investigate this.

## Task

Your task is to create a program which will read a line of space-delimited
numbers and operators, and print out the result from the calculation. Answers
should be separated by a newline as shown in the *Sample Input* section. You may
assume that all input is well-formed, but if you wish to include more graceful
error handling you may.

The end of input is marked by the sentinel character '#'. After this character
has been entered your program should exit.

The allowed operators are `+` for addition, `-` for subtraction, `*` for
multiplication and `/` for division. Numbers may be assumed to be positive
integers.

## Sample Input

### Case 1

Input:
```text
5 2 +
#
```

Output:
```text
7
#
```

### Case 2

Input:
```text
5 2 + 6 - 2 *
#
```

Output:
```text
2
```

### Case 3

Input:
```text
8 2 *
5 1 -
#
```

Output:
```text
16
4
```
