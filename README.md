*This project has been created as part of the 42 curriculum by akechedz*

# push_swap

This project is about sorting data in a stack using a limited set of operations. The goal is to sort the stack with as few operations as possible. Several algorithms were looked at, and the most efficient one for the job was picked.

# Description

## The problem

There are two stacks, **a** and **b**.

- At the start, stack **a** holds a random number of unique negative and/or positive integers.
- Stack **b** starts empty.
- The goal is to sort the numbers in stack **a** in ascending order (smallest on top).

Only these operations are allowed:

| Op    | Name              | Effect                                                                                     |
|-------|-------------------|--------------------------------------------------------------------------------------------|
| `sa`  | swap a            | Swap the first 2 elements at the top of **a**. Does nothing if there is one element or none. |
| `sb`  | swap b            | Swap the first 2 elements at the top of **b**. Does nothing if there is one element or none. |
| `ss`  | swap both         | `sa` and `sb` at the same time.                                                            |
| `pa`  | push a            | Take the top element of **b** and put it on top of **a**. Does nothing if **b** is empty.  |
| `pb`  | push b            | Take the top element of **a** and put it on top of **b**. Does nothing if **a** is empty.  |
| `ra`  | rotate a          | Shift every element of **a** up by 1. The first element becomes the last one.             |
| `rb`  | rotate b          | Shift every element of **b** up by 1. The first element becomes the last one.             |
| `rr`  | rotate both       | `ra` and `rb` at the same time.                                                            |
| `rra` | reverse rotate a  | Shift every element of **a** down by 1. The last element becomes the first one.           |
| `rrb` | reverse rotate b  | Shift every element of **b** down by 1. The last element becomes the first one.           |
| `rrr` | reverse rotate both | `rra` and `rrb` at the same time.                                                        |

The program `push_swap` takes the integers as arguments and prints the shortest list of operations it can find that sorts them, one per line, to standard output.

## How it works

### 1. Parsing and validation (`parse/`)

- Each argument is split on spaces with `ft_split`, so `./push_swap 3 2 1` and `./push_swap "3 2 1"` both work, and so does a mix of the two.
- `atoi_precheck` accepts an optional `+`/`-` sign followed by digits only. An empty string, a lone sign or any other character is rejected.
- `ft_atol` converts the string to a `long`, and values outside `INT_MIN`..`INT_MAX` are rejected. The conversion stops early once the value goes past `INT_MAX + 1`, so very long numbers cannot overflow the `long`.
- `dub_check` rejects duplicate values.
- On any error, the program frees everything and prints `Error`.

### 2. Data structure

Each stack is a **doubly linked list** with pointers to its `first` (top) and `last` (bottom) nodes and a `size` counter:

```c
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;
```

With both ends stored, `push`, `rotate` and `reverse_rotate` run in constant time. `swap` relinks the two top nodes instead of swapping their `data`, because each node also carries its `index`, and the node itself is what moves.

### 3. Normalization

After parsing, `stk_normalize` replaces each value's position in the sorted order with a **rank** (`index` from `0` to `n - 1`). The algorithms only work with these ranks, so the actual values (negative numbers, big gaps) do not matter. `check_sorted` uses the ranks too: the stack is sorted when the indexes read `0, 1, 2, ...` from top to bottom. If the input is already sorted, nothing is printed.

### 4. Sorting

The program picks the algorithm based on the input size:

- **Fewer than 7 numbers: `mini_sort`** (`sort_algo/mini_sort.c`)
  1. `push_smallest` pushes every element except the 3 largest to **b**. For each one it looks from both ends of **a** at once and uses `ra` or `rra`, whichever reaches a small element sooner.
  2. `micro_sort` sorts the 3 elements left in **a** with at most 2 operations.
  3. `reverse_micro_sort` sorts **b** in descending order the same way.
  4. Everything is pushed back with `pa`.

- **7 numbers or more: K-sort** (`sort_algo/k_sort.c`), a K-distribution sort:
  1. **Distribution (`k_sort`)**: a window of ranks `[0, threshold + delta]` slides upward, with `delta = n / 20 + 7`. If the top of **a** is inside the window, it is pushed to **b** (`pb`) and `threshold` moves up by one. If the pushed element is also `<= threshold`, it is rotated to the bottom of **b** (`rb`). Otherwise **a** is rotated (`ra`). This leaves **b** roughly sorted, with large ranks near the top and small ranks near the bottom.
  2. **Reintegration (`reintegrate`)**: the largest rank left in **b** is found and moved to the top using `rb` or `rrb`, whichever path is shorter. It is then pushed to **a** (`pa`). Repeating this builds **a** sorted from the largest value down to the smallest.

### Results

Measured on 20 random inputs per size and verified with `checker_linux`:

| Numbers | Average ops | Max ops |
|--------:|------------:|--------:|
| 3       | 1           | 2       |
| 5       | 7           | 9       |
| 100     | 579         | 626     |
| 500     | 5076        | 5226    |

## Project layout

```
push_swap/
├── main.c               # entry point: parse -> pick algorithm -> print ops -> free
├── push_swap.c          # stack helpers: init, free, normalize, check_sorted, print_list
├── push_swap.h
├── parse/
│   ├── parse.c          # argument splitting, filling stack a
│   └── validation.c     # number format and duplicate checks
├── sort_algo/
│   ├── mini_sort.c      # < 7 elements
│   └── k_sort.c         # >= 7 elements, plus reintegrate
├── stk_ops/             # sa sb ss pa pb ra rb rr rra rrb rrr
├── utils/ft_atol.c
└── libft/               # own libft, including ft_printf
```

# Instructions

## Compilation

```sh
make        # builds libft/libft.a and then ./push_swap
make clean  # removes object files (also in libft)
make fclean # removes object files, libft.a and the push_swap binary
make re     # fclean + all
```

The project compiles with `cc -Wall -Wextra -Werror`. libft is linked with `-L libft -lft`: `-lft` tells the linker to look for `libft.a` (`-l<name>` → `lib<name>.a`).

## Usage

```sh
./push_swap 2 1 3 6 5 8
./push_swap "3 2 1"
./push_swap -5 "42 0" 7
```

- No arguments: prints nothing.
- Invalid input (not a number, empty string, duplicate, outside the `int` range): prints `Error`.
- Already sorted input: prints nothing.

## Checking the result

The checker binaries provided with the subject are kept in `misc/`. Pipe the output of `push_swap` into the checker with the same arguments:

```sh
ARG="3 2 1"; ./push_swap $ARG | ./misc/checker_linux $ARG     # OK / KO
ARG="3 2 1"; ./push_swap $ARG | wc -l                         # number of operations
```

You can also send a sequence of operations to the checker by hand:

```sh
echo "pb\npb\npb\nrrb\npa\nrrb\npa\npa" | ./misc/checker_linux 3 2 1
```

Random test input:

```sh
ARG=$(shuf -i 1-100000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./misc/checker_linux $ARG
```

## Debugging

The `main.c` in the repository is the norm-compliant version that gets turned in. The norm does not allow preprocessor directives inside functions, so the debug version of `main()` is kept here in the README instead. It is the same program with `#ifdef DEBUG` blocks that print the stacks (`value[index] -> ...`) and their sizes after parsing, after distribution and at the end. Without `-DDEBUG` it behaves exactly like the turned-in version.

To use it:

```sh
make main                  # overwrite main.c with the debug version below
make debug ARG="3 2 1"     # rebuild with -DDEBUG and run ./push_swap 3 2 1
git checkout main.c        # restore the norm-compliant main.c
make re                    # rebuild without debug output
```

`make debug` is the same as `make re CFLAGS="-Wall -Wextra -Werror -g -DDEBUG"` followed by `./push_swap $(ARG)`.

`make main` takes the first code block marked `C` in this README, so keep it the only one. Never turn in the generated `main.c`: it has no 42 header and does not pass norminette.

Other Makefile targets (`ARG` defaults to `2 1 3 6 5 8`):

- `make run ARG="..."` builds the program and runs `./push_swap $(ARG)`.
- `make test ARG="..."` builds the program and runs it under `valgrind --leak-check=full --show-leak-kinds=all` if valgrind is installed, or runs it normally if it is not.

### main.c (debug version)

```C
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stk_init();
	if (!a)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		stk_free(a);
		return (ft_printf("Error\n"), 1);
	}
#ifdef DEBUG
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
#endif
	if (check_sorted(a))
		return (stk_free(a), 0);
	b = stk_init();
	if (!b)
	{
		stk_free(a);
		stk_free(b);
		return (ft_printf("Error\n"), 1);
	}
	if (a->size < 7)
		mini_sort(a, b);
	else
		k_sort(a, b);
#ifdef DEBUG
	print_list(b->first);
	ft_printf("B_SIZE=%d\n", b->size);
#endif
	reintegrate(a, b);
#ifdef DEBUG
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
#endif
	stk_free(a);
	stk_free(b);
	return (0);
}
```

# Resources

- [Insertion in a doubly circular linked list (GeeksforGeeks)](https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/): linking and unlinking nodes in a doubly linked list.
- [Python Tutor](https://pythontutor.com/visualize.html#mode=edit): a step-by-step visualizer, used to check pointer changes in the stack operations.
- [push_swap visualizer](https://push-swap42-visualizer.vercel.app/): animates a list of operations on both stacks.
- [K-distribution sort applied to the push_swap problem (Medium)](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376): the idea behind `k_sort` and `reintegrate`.
- The 42 `push_swap` subject and the provided `checker_linux` / `checker_Mac` binaries.

## AI usage

AI (Claude) was used to:

- write and structure this README from the source code and its comments;
- benchmark the operation counts in the **Results** table and check them with the provided checker.
