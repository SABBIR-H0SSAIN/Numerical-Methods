# Gauss-Jordan Elimination Method

## Theory

Gauss-Jordan Elimination is an extension of Gauss Elimination that transforms the augmented matrix $[A|b]$ into Reduced Row Echelon Form (RREF). Unlike Gauss Elimination, it eliminates elements both above and below each pivot, and scales pivots to 1.

The solution is directly read from the final column without back substitution.

## Method

Given system $Ax = b$:

1. Form augmented matrix $[A|b]$
2. For each column, make the pivot element 1 by scaling the row
3. Eliminate all other elements in the pivot column (above and below)
4. Final form: $[I|x]$ where $x$ is the solution

## Solution Types

Using rank analysis:

- $\text{rank}(A) < \text{rank}(A|b)$ → No Solution
- $\text{rank}(A) = \text{rank}(A|b) < n$ → Infinite Solutions
- $\text{rank}(A) = \text{rank}(A|b) = n$ → Unique Solution
