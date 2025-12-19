# Matrix Inversion Method

## Theory

Matrix Inversion solves the system $Ax = b$ by computing the inverse of $A$:

$$x = A^{-1}b$$

The inverse $A^{-1}$ is found using Gauss-Jordan elimination on the augmented matrix $[A|I]$.

A matrix is invertible if and only if its determinant is non-zero, or equivalently, $\text{rank}(A) = n$.

## Method

To solve $Ax = b$:

1. Form augmented matrix $[A|I]$
2. Apply Gauss-Jordan elimination to get $[I|A^{-1}]$
3. Compute solution: $x = A^{-1} \times b$

## Solution Types

Using rank analysis:

- $\text{rank}(A) < \text{rank}(A|b)$ -> No Solution
- $\text{rank}(A) = \text{rank}(A|b) < n$ -> Infinite Solutions (A not invertible)
- $\text{rank}(A) = \text{rank}(A|b) = n$ -> Unique Solution (A is invertible)
