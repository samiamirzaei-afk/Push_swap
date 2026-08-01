_This project has been created as part of the 42 curriculum by ammirzae and sfurst._

# push_swap

## Description

`push_swap` sorts a list of unique integers in ascending order. At the start, all values are stored in stack A and stack B is empty. The program may not move the values freely: it has to produce a sequence made from the limited set of operations below.

The project contains three sorting strategies and an adaptive mode which picks one of them based on how disordered the input is. It also includes an optional benchmark mode and a bonus `checker` program.

## Available operations

* `pa` (push A): Move the top element of B to the top of A. Does nothing if B is empty.
* `pb` (push B): Move the top element of A to the top of B. Does nothing if A is empty.
* `sa` (swap A): Swap the first two elements of A. Does nothing if A contains fewer than two elements.
* `sb` (swap B): Swap the first two elements of B. Does nothing if B contains fewer than two elements.
* `ss`: Perform `sa` and `sb` at the same time.
* `ra` (rotate A): Shift every element of A up by one; the first element becomes the last.
* `rb` (rotate B): Shift every element of B up by one; the first element becomes the last.
* `rr`: Perform `ra` and `rb` at the same time.
* `rra` (reverse rotate A): Shift every element of A down by one; the last element becomes the first.
* `rrb` (reverse rotate B): Shift every element of B down by one; the last element becomes the first.
* `rrr`: Perform `rra` and `rrb` at the same time.

## Sorting algorithms

Before sorting, every value is assigned an index from `0` to `n - 1`. The smallest value receives index `0`, the next smallest index `1`, and so on. This coordinate compression lets the chunk and radix strategies work with ranks instead of the original values, including negative numbers.

For inputs of five values or fewer, all three strategies use the same small-sort routine. It moves the smallest values to B until at most three remain, sorts those values directly, and then pushes the saved values back to A.

### Simple: minimum-selection sort

Reason: We chose this strategy because the idea is straightforward and its behavior is easy to follow while working with two stacks.

Description: Despite the internal function name `bubble_sort`, this strategy is closer to selection sort. It repeatedly finds the smallest value in A, rotates A in the shorter direction until that value reaches the top, and pushes it to B. It may also swap the top two values when they are inverted. Once the remaining part of A is sorted, every saved value is pushed back from B to A. Because minima were pushed in increasing order, B holds them in descending order from top to bottom, so the final pushes produce an ascending stack A.

The worst-case time complexity is `O(n²)` because each minimum search scans the remaining stack.

### Medium: chunk sort

Reason: We selected chunk sorting as a middle ground between the simple method and radix sort. It is still fairly easy to understand, while reducing the amount of searching done over the complete input.

Description: The algorithm divides the normalized indexes into consecutive chunks of approximately `sqrt(n)` elements. For each chunk, it rotates A until an index inside the current range reaches the top, then pushes that value to B. After all values have been transferred, it repeatedly finds the largest index in B, rotates B toward it using the shorter direction, and pushes it to A. The largest remaining value is therefore placed on A first, producing ascending order as B is emptied.

With chunks of size `sqrt(n)`, the intended time complexity is `O(n√n)`.

### Complex: binary radix sort

Reason: Binary radix sort works especially well after replacing the input values with indexes. It is predictable, stable, and efficient for larger input sizes.

Description: The algorithm processes the index bits from least significant to most significant. For each bit it examines exactly the number of values that were originally in A:

* If `(index >> bit) & 1` is `0`, it performs `pb`.
* If `(index >> bit) & 1` is `1`, it performs `ra`.

After one complete pass, every value in B is pushed back to A with `pa`. The rotations preserve the order of the 1-bit group, while pushing to B and then back to A preserves the order of the 0-bit group. This creates a stable binary partition for each bit. Once all bits needed to represent the indexes have been processed, A is sorted.

The time complexity is `O(n log n)` for indexes in the range `0` to `n - 1`.

### Adaptive mode

Adaptive mode measures disorder as the proportion of inverted pairs in the input. A sorted list has `0%` disorder and a reverse-sorted list has `100%`. It then selects a strategy using these thresholds:

* Below `20%`: simple sort
* From `20%` up to, but not including, `50%`: chunk sort
* `50%` or above: radix sort

Adaptive mode is used by default when no sorting flag is supplied.

## Benchmark mode

Adding `--bench` leaves the generated operations on standard output and prints benchmark information to standard error. The report contains:

* the input disorder percentage;
* the selected strategy, including the strategy selected by adaptive mode;
* the total number of operations;
* a count for every individual operation.

Keeping the report on standard error means the operation stream can still be piped directly into `checker`.

## Instructions

Compile the main program with:

```sh
make
```

This creates the `push_swap` executable. Compile the bonus checker with:

```sh
make bonus
```

The program accepts unique signed 32-bit integers as separate arguments. Flags may appear anywhere in the argument list:

```sh
./push_swap 4 2 7 1 3
./push_swap --medium 4 2 7 1 3
./push_swap 4 2 7 1 3 --complex --bench
```

Available flags are:

* `--simple`: use minimum-selection sort;
* `--medium`: use chunk sort;
* `--complex`: use binary radix sort;
* `--adaptive`: choose a strategy from the disorder percentage;
* `--bench`: print benchmark statistics to standard error.

If multiple strategy flags are provided, the last one takes effect. Invalid integers, values outside the signed 32-bit range, duplicates, unknown flags, or an empty input produce `Error` on standard error.

To verify the generated instructions with the bonus checker:

```sh
ARG="4 2 7 1 3"
./push_swap $ARG | ./checker $ARG
```

The checker reads operations from standard input and prints `OK` when stack A is sorted and stack B is empty. It prints `KO` for a valid operation sequence that does not reach that state, and `Error` for invalid input or an unknown instruction.

## Collaboration

Samy originally started the project without a reliable teammate, so Veya joined him for a retry. This resulted in a slightly unusual workflow. Samy kept working on his existing branch, where he implemented the sorting algorithms and the main functionality. Veya reorganized the general structure, ported Samy's code into the cleaner structure, optimized the benchmark output to use a single `write` call, and added the bonus checker.

The work was divided as follows:

### Samy

* Implementing all sorting algorithms
* Working out the general sorting logic
* Contributing to the benchmark mode
* Testing

### Veya

* Cleaning up and reorganizing the project structure
* Testing
* Implementing the bonus checker
* Merging the code into the final structure

The final version was reviewed together. Samy's original code was kept as close to its initial form as reasonably possible, and both contributors made sure they understood the complete project. Since this was Veyas's retry, the exploratory parts of the project were left to Samy wherever possible so that he could learn from the process.

## Resources

### Algorithms

* [Selection sort](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
* [Radix sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
* [push_swap subject](https://cdn.intra.42.fr/pdf/pdf/222599/en.subject.pdf)

### AI usage

Getting a draft of the readme and spellchecking.
