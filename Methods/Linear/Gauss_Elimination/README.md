# Gauss Elimination Method

## Theory

Gauss Elimination is a method to solve a system of linear equations Ax = b.

**Steps:**

1. Convert the augmented matrix [A|b] to upper triangular form using row operations
2. Use back substitution to find the solution

**Solution Types (using rank):**

- If rank(A) < rank(A|b) -> No Solution
- If rank(A) = rank(A|b) < n -> Infinite Solutions
- If rank(A) = rank(A|b) = n -> Unique Solution
