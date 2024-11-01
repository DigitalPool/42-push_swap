# Push Swap: A 42 Project to Master Stack-Based Sorting 🎩

Welcome to **Push Swap**, where your mission is to sort a set of integers using only two stacks and a limited set of operations. This project is designed to test your algorithmic skills, especially in the art of sequential access sorting. Let’s dive into the world of stack manipulation, efficient sorting, and optimized move counts to achieve a clean, organized stack!

## 🌟 Goal

Sort integers in ascending order using only two stacks (A and B) and a predefined set of operations. The challenge? Use the fewest moves possible to optimize your solution. Achieving efficiency in this constrained environment is key, as each move counts!

**Grade Achieved**: 125/100 🌟

## 🔄 Instruction Set

Here’s the arsenal of operations you’ll use to manage and sort the stacks:

| Code | Instruction         | Action                                            |
|------|----------------------|---------------------------------------------------|
| `sa` | swap a              | Swaps the top two elements of stack A.            |
| `sb` | swap b              | Swaps the top two elements of stack B.            |
| `ss` | swap a + swap b     | Performs `sa` and `sb` simultaneously.            |
| `pa` | push a              | Moves the top element of stack B to stack A.      |
| `pb` | push b              | Moves the top element of stack A to stack B.      |
| `ra` | rotate a            | Shifts all elements in stack A from bottom to top.|
| `rb` | rotate b            | Shifts all elements in stack B from bottom to top.|
| `rr` | rotate a + rotate b | Performs `ra` and `rb` simultaneously.            |
| `rra`| reverse rotate a    | Shifts all elements in stack A from top to bottom.|
| `rrb`| reverse rotate b    | Shifts all elements in stack B from top to bottom.|
| `rrr`| reverse rotate a + b| Performs `rra` and `rrb` simultaneously.          |

## 🧠 Algorithm

The Push Swap project employs a **Radix Sort** algorithm, ideal for handling integers with high efficiency. Here’s a breakdown of how it works:

### Small Stack Sort (Size < 6)

For stacks with fewer than six elements, a simple sort (found in the `src` folder) handles the arrangement quickly and with minimal operations.

### Radix Sort for Larger Sets

For larger sets, we use **Radix Sort** (base-2), ideal for sequential access. The algorithm:

1. **Simplifies Numbers**: Large numbers are compressed by assigning them relative ranks.
2. **Base-2 Representation**: The numbers are then represented in binary, using only two stacks (A and B) for sorting.
3. **Bit-by-Bit Sorting**:
   - Process each bit from least significant to most significant.
   - If the bit is `0`, move the number to stack B (`pb`).
   - If the bit is `1`, rotate stack A (`ra`), keeping the number in A.
4. **Repeat** for all bits, moving all elements back to A after each pass.

### Performance

Push Swap is optimized to perform within strict move limits:
- **3 numbers**: ≤ 3 moves
- **4 numbers**: ≤ 7 moves
- **5 numbers**: ≤ 11 moves
- **100 numbers**: ≤ 1084 moves
- **500 numbers**: ≤ 6785 moves

The Radix Sort adaptation ensures these constraints are met, maximizing efficiency.

## 🎮 Bonus: Checker Program

The **Checker** program is an added feature that verifies whether a series of operations successfully sorts a stack. Here’s how it works:

1. **Input**: Take an initial stack as input and wait for a list of operations from standard input.
2. **Validation**: Execute the operations on the stack.
3. **Output**: If sorted and stack B is empty, output `OK`. If not, output `KO`. Invalid inputs return `Error`.

This Checker is useful for debugging and allows step-by-step monitoring to visualize each operation.

## 🛠️ Usage

### Basic Usage

To compile and execute:

```bash
make              # Compiles the push_swap executable
./push_swap [m] INT_LIST   # Run with an optional 'm' flag for step-by-step monitoring
```

For example:
```bash
./push_swap 4 3 2 1
```

### Checker Usage

To compile and execute the Checker:

```bash
make bonus        # Compiles the checker executable
./checker [m] INT_LIST
```

To use Checker, provide instructions via stdin and finish with `CTRL + D`:

```bash
echo -e "pb\npb\nsa\npa\npa" | ./checker 4 2 3 1
```

Happy sorting, and may your moves be minimal! 🏆
