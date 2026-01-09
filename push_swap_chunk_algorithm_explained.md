# Push_Swap Chunk-Based Sorting Algorithm Explained

## 1. Overview

This document explains in detail how a chunk-based sorting algorithm for
the **push_swap** project works, from start to finish. The algorithm
sorts stack **A** using an auxiliary stack **B**, achieving an average
time complexity of **O(n√n)** with excellent practical performance.

------------------------------------------------------------------------

## 2. Core Idea

The algorithm works in two main phases:

1.  **Scatter phase (A → B)**\
    Elements are pushed from stack A to stack B in small groups called
    *chunks*.
2.  **Gather phase (B → A)**\
    Stack B is rebuilt back into stack A by always extracting the
    maximum element.

To make movement efficient, values are replaced by **ranks**, allowing
uniform chunk boundaries.

------------------------------------------------------------------------

## 3. Rank Assignment

### Why ranks?

Actual values can be large and unevenly distributed. Ranks normalize the
problem:

-   Smallest value → rank 0
-   Largest value → rank n − 1

### How it works

1.  Copy all values from stack A into an array
2.  Sort the array
3.  For each node in stack A:
    -   Binary-search its value in the sorted array
    -   Assign its index as `rank`

Example:

Stack A values:

    42  -3  15  7

Sorted array:

    -3  7  15  42

Assigned ranks:

    42 → 3
    -3 → 0
    15 → 2
    7  → 1

------------------------------------------------------------------------

## 4. Chunk Strategy

### Chunk size

Chunk size is chosen proportional to √n:

-   For 100 elements → \~15
-   For 500 elements → \~30

This creates approximately √n chunks.

------------------------------------------------------------------------

## 5. Scatter Phase (A → B)

### Goal

Move elements from A to B **chunk by chunk**, minimizing rotations.

### Key optimization

Instead of blindly rotating A: - Search for the nearest element
belonging to the current chunk - Rotate in the shortest direction - Push
it to B

This avoids unnecessary rotations.

### Example

Suppose current chunk ranks are \[0--4\]:

Stack A (top → bottom):

    7  1  9  3  6

Ranks:

    7→4, 1→0, 9→6, 3→2, 6→3

Nearest valid rank is `1` at position 1: - Rotate once - Push to B

------------------------------------------------------------------------

### Ordering inside B

After pushing to B: - If rank \> chunk midpoint → rotate B

This gently pre-sorts B so larger elements are easier to extract later.

------------------------------------------------------------------------

## 6. Gather Phase (B → A)

### Goal

Rebuild stack A in sorted order.

### Strategy

While B is not empty: 1. Find the maximum rank in B 2. Rotate B in the
shortest direction 3. Push it to A

This guarantees A grows sorted from bottom to top.

------------------------------------------------------------------------

### Example

Stack B:

    2  5  1  4  3

Max = 5\
Rotate B until 5 is on top → `pa`

Repeat until B is empty.

------------------------------------------------------------------------

## 7. Why the Algorithm Is Efficient

### Scatter Phase Complexity

-   √n chunks
-   √n pushes per chunk
-   Each push costs O(n / √n) rotations on average

Total:

    √n × √n × (n / √n) = O(n√n)

------------------------------------------------------------------------

### Gather Phase Complexity

-   n pushes
-   Average of √n rotations per push (thanks to chunk ordering)

Total:

    n × √n = O(n√n)

------------------------------------------------------------------------

## 8. Overall Complexity

  Phase             Complexity
  ----------------- ------------------
  Rank assignment   O(n²) (one-time)
  Scatter           O(n√n)
  Gather            O(n√n)
  **Total**         **O(n√n)**

The one-time ranking cost does not dominate movement cost.

------------------------------------------------------------------------

## 9. Why This Works Well in Push_Swap

-   Avoids blind rotations
-   Uses directional movement
-   Reduces entropy early
-   Exploits structure during reconstruction

This results in: - \~600 operations for 100 elements - \~6000 operations
for 500 elements

------------------------------------------------------------------------

## 10. Key Takeaways

-   Chunking reduces problem complexity
-   Intentional rotations save operations
-   Early structure enables greedy efficiency
-   Push_swap rewards *movement strategy*, not just theory

------------------------------------------------------------------------

## End
