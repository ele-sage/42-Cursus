# push_swap

This project is about sorting data. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

The goal is to write 2 programs in C:
- The first, called `push_swap` will calculate and display on the standard output the smallest list of instructions possible to sort the integer arguments received.

- The second, called `checker` will read the instructions given by `push_swap` on the standard output and apply them to the integer arguments received. If after applying the instructions, the stack is sorted, `checker` will display `OK`, otherwise it will display `KO`.

## Usage

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

## Rules

- The game is composed of 2 stacks named `a` and `b`.
- To start with:
  - `a` contains a random number of either positive or negative numbers without any duplicates.
  - `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`.
- To do this you have the following operations at your disposal:
  - `sa`: swap `a` - swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
  - `sb`: swap `b` - swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
  - `ss`: `sa` and `sb` at the same time.
  - `pa`: push `a` - take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
  - `pb`: push `b` - take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
  - `ra`: rotate `a` - shift up all elements of stack `a` by 1. The first element becomes the last one.
  - `rb`: rotate `b` - shift up all elements of stack `b` by 1. The first element becomes the last one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra`: reverse rotate `a` - shift down all elements of stack `a` by 1. The last element becomes the first one.
  - `rrb`: reverse rotate `b` - shift down all elements of stack `b` by 1. The last element becomes the first one.
  - `rrr`: `rra` and `rrb` at the same time.