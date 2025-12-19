# LU Decomposition Method

## Theory

LU Decomposition factors a matrix $A$ into the product of two triangular matrices:

$$A = LU$$

Where:

- $L$ = Lower triangular matrix (with 1s on diagonal)
- $U$ = Upper triangular matrix

This is efficient when solving multiple systems with the same coefficient matrix but different right-hand sides.

## Method

To solve $Ax = b$:

1. Decompose: $A = LU$
2. Substitute: $LUx = b$, let $Ux = y$
3. Solve $Ly = b$ using forward substitution
4. Solve $Ux = y$ using backward substitution

## Solution Types

Using rank analysis:

- $\text{rank}(A) < \text{rank}(A|b)$ → No Solution
- $\text{rank}(A) = \text{rank}(A|b) < n$ → Infinite Solutions
- $\text{rank}(A) = \text{rank}(A|b) = n$ → Unique Solution
