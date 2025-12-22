# Numerical Methods
### Introduction

This repository contains **19 numerical methods** organized into **7 categories**, each with complete C++ implementations, mathematical theory, and test cases. All methods follow a consistent structure: **Theory**, **Code**, **Input**, and **Output**.

**Categories:**
- Solution of Linear Equations (4 methods)
- Solution of Non-Linear Equations (4 methods)
- Interpolation (3 methods)
- Numerical Integration (2 methods)
- Numerical Differentiation (2 methods)
- Regression (3 methods)
- Ordinary Differential Equations (1 method)

---

# Table of Contents

- [Solution of Linear Equations](#solution-of-linear-equations)
  - [Gauss Elimination Method](#gauss-elimination-method)
    - [Theory](#gauss-elimination-theory)
    - [Code](#gauss-elimination-code)
    - [Input](#gauss-elimination-input)
    - [Output](#gauss-elimination-output)
  - [Gauss-Jordan Elimination Method](#gauss-jordan-elimination-method)
    - [Theory](#gauss-jordan-elimination-theory)
    - [Code](#gauss-jordan-elimination-code)
    - [Input](#gauss-jordan-elimination-input)
    - [Output](#gauss-jordan-elimination-output)
  - [LU Decomposition Method](#lu-decomposition-method)
    - [Theory](#lu-decomposition-theory)
    - [Code](#lu-decomposition-code)
    - [Input](#lu-decomposition-input)
    - [Output](#lu-decomposition-output)
  - [Matrix Inversion Method](#matrix-inversion-method)
    - [Theory](#matrix-inversion-theory)
    - [Code](#matrix-inversion-code)
    - [Input](#matrix-inversion-input)
    - [Output](#matrix-inversion-output)
- [Solution of Non-Linear Equations](#solution-of-non-linear-equations)
  - [Bisection Method](#bisection-method)
    - [Theory](#bisection-theory)
    - [Code](#bisection-code)
    - [Input](#bisection-input)
    - [Output](#bisection-output)
  - [False Position Method](#false-position-method)
    - [Theory](#false-position-theory)
    - [Code](#false-position-code)
    - [Input](#false-position-input)
    - [Output](#false-position-output)
  - [Newton-Raphson Method](#newton-raphson-method)
    - [Theory](#newton-raphson-theory)
    - [Code](#newton-raphson-code)
    - [Input](#newton-raphson-input)
    - [Output](#newton-raphson-output)
  - [Secant Method](#secant-method)
    - [Theory](#secant-theory)
    - [Code](#secant-code)
    - [Input](#secant-input)
    - [Output](#secant-output)
- [Interpolation](#interpolation)
  - [Divided Difference Method](#divided-difference-method)
    - [Theory](#divided-difference-theory)
    - [Code](#divided-difference-code)
    - [Input](#divided-difference-input)
    - [Output](#divided-difference-output)
  - [Newtons Forward Interpolation Method](#newtons-forward-interpolation-method)
    - [Theory](#newtons-forward-interpolation-theory)
    - [Code](#newtons-forward-interpolation-code)
    - [Input](#newtons-forward-interpolation-input)
    - [Output](#newtons-forward-interpolation-output)
  - [Newtons Backward Interpolation Method](#newtons-backward-interpolation-method)
    - [Theory](#newtons-backward-interpolation-theory)
    - [Code](#newtons-backward-interpolation-code)
    - [Input](#newtons-backward-interpolation-input)
    - [Output](#newtons-backward-interpolation-output)
- [Numerical Integration](#numerical-integration)
  - [Simpsons One Third Rule Method](#simpsons-one-third-rule-method)
    - [Theory](#simpsons-one-third-rule-theory)
    - [Code](#simpsons-one-third-rule-code)
    - [Input](#simpsons-one-third-rule-input)
    - [Output](#simpsons-one-third-rule-output)
  - [Simpsons Three Eighth Rule Method](#simpsons-three-eighth-rule-method)
    - [Theory](#simpsons-three-eighth-rule-theory)
    - [Code](#simpsons-three-eighth-rule-code)
    - [Input](#simpsons-three-eighth-rule-input)
    - [Output](#simpsons-three-eighth-rule-output)
- [Numerical Differentiation](#numerical-differentiation)
  - [Newtons Forward Difference Method](#newtons-forward-difference-method)
    - [Theory](#newtons-forward-difference-theory)
    - [Code](#newtons-forward-difference-code)
    - [Input](#newtons-forward-difference-input)
    - [Output](#newtons-forward-difference-output)
  - [Newtons Backward Difference Method](#newtons-backward-difference-method)
    - [Theory](#newtons-backward-difference-theory)
    - [Code](#newtons-backward-difference-code)
    - [Input](#newtons-backward-difference-input)
    - [Output](#newtons-backward-difference-output)
- [Regression](#regression)
  - [Linear Regression Method](#linear-regression-method)
    - [Theory](#linear-regression-theory)
    - [Code](#linear-regression-code)
    - [Input](#linear-regression-input)
    - [Output](#linear-regression-output)
  - [Polynomial Regression Method](#polynomial-regression-method)
    - [Theory](#polynomial-regression-theory)
    - [Code](#polynomial-regression-code)
    - [Input](#polynomial-regression-input)
    - [Output](#polynomial-regression-output)
  - [Transcendental Regression Method](#transcendental-regression-method)
    - [Theory](#transcendental-regression-theory)
    - [Code](#transcendental-regression-code)
    - [Input](#transcendental-regression-input)
    - [Output](#transcendental-regression-output)
- [Ordinary Differential Equations](#ordinary-differential-equations)
  - [Runge-Kutta 4th Order (RK4) Method](#runge-kutta-4th-order-rk4-method)
    - [Theory](#runge-kutta-4th-order-rk4-theory)
    - [Code](#runge-kutta-4th-order-rk4-code)
    - [Input](#runge-kutta-4th-order-rk4-input)
    - [Output](#runge-kutta-4th-order-rk4-output)

---

## Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory

## Theory

Gauss Elimination is a method to solve a system of linear equations Ax = b.

**Steps:**

1. Convert the augmented matrix [A|b] to upper triangular form using row operations
2. Use back substitution to find the solution

**Solution Types (using rank):**

- If rank(A) < rank(A|b) -> No Solution
- If rank(A) = rank(A|b) < n -> Infinite Solutions
- If rank(A) = rank(A|b) = n -> Unique Solution

#### Gauss Elimination Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int calculateRank(vector<vector<double>> mat, int rows, int cols)
{
    int rank = 0;
    for (int col = 0, row = 0; col < cols && row < rows; col++)
    {
        int maxRow = row;
        for (int k = row + 1; k < rows; k++)
        {
            if (abs(mat[k][col]) > abs(mat[maxRow][col]))
            {
                maxRow = k;
            }
        }

        if (abs(mat[maxRow][col]) < EPS)
        {
            continue;
        }

        swap(mat[row], mat[maxRow]);

        for (int k = row + 1; k < rows; k++)
        {
            double factor = mat[k][col] / mat[row][col];
            for (int j = col; j < cols; j++)
            {
                mat[k][j] -= factor * mat[row][j];
            }
        }
        rank++;
        row++;
    }
    return rank;
}

int checkSolutionType(vector<vector<double>> &augMatrix, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = augMatrix[i][j];
        }
    }

    rankA = calculateRank(A, n, n);
    rankAug = calculateRank(augMatrix, n, n + 1);

    if (rankA < rankAug)
    {
        return -1;
    }
    else if (rankA < n)
    {
        return 1;
    }
    return 0;
}

void solveSystem(vector<vector<double>> a, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, n, rankA, rankAug);

    if (solutionType == -1)
    {
        fout << "Solution Type: NO SOLUTION" << endl;
    }
    else if (solutionType == 1)
    {
        fout << "Solution Type: INFINITE SOLUTIONS" << endl;
    }
    else
    {
        fout << "Solution Type: UNIQUE SOLUTION" << endl;

        for (int col = 0, row = 0; col < n && row < n; col++)
        {
            int maxRow = row;
            for (int k = row + 1; k < n; k++)
            {
                if (abs(a[k][col]) > abs(a[maxRow][col]))
                {
                    maxRow = k;
                }
            }

            if (abs(a[maxRow][col]) < EPS)
            {
                continue;
            }

            swap(a[row], a[maxRow]);

            for (int k = row + 1; k < n; k++)
            {
                double factor = a[k][col] / a[row][col];
                for (int j = col; j <= n; j++)
                {
                    a[k][j] -= factor * a[row][j];
                }
            }
            row++;
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }

        fout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << "x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fout << endl
         << endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << fixed << setprecision(6);
    fout << "Gauss Elimination Method" << endl;
    fout << "========================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        solveSystem(a, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}

```

#### Gauss Elimination Input

```
3

3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

3
1 2 3 6
2 4 6 12
1 1 1 3

3
1 2 3 6
2 4 6 12
1 2 3 10

```

#### Gauss Elimination Output

```
Gauss Elimination Method
========================

Problem 1
----------------------------------------
Solution Type: UNIQUE SOLUTION
Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000


Problem 2
----------------------------------------
Solution Type: INFINITE SOLUTIONS


Problem 3
----------------------------------------
Solution Type: NO SOLUTION



```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Gauss-Jordan Elimination Method

#### Gauss-Jordan Elimination Theory

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

#### Gauss-Jordan Elimination Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int calculateRank(vector<vector<double>> mat, int rows, int cols)
{
    int rank = 0;
    for (int col = 0, row = 0; col < cols && row < rows; col++)
    {
        int maxRow = row;
        for (int k = row + 1; k < rows; k++)
        {
            if (abs(mat[k][col]) > abs(mat[maxRow][col]))
            {
                maxRow = k;
            }
        }

        if (abs(mat[maxRow][col]) < EPS)
        {
            continue;
        }

        swap(mat[row], mat[maxRow]);

        for (int k = row + 1; k < rows; k++)
        {
            double factor = mat[k][col] / mat[row][col];
            for (int j = col; j < cols; j++)
            {
                mat[k][j] -= factor * mat[row][j];
            }
        }
        rank++;
        row++;
    }
    return rank;
}

int checkSolutionType(vector<vector<double>> &augMatrix, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = augMatrix[i][j];
        }
    }

    rankA = calculateRank(A, n, n);
    rankAug = calculateRank(augMatrix, n, n + 1);

    if (rankA < rankAug)
    {
        return -1;
    }
    else if (rankA < n)
    {
        return 1;
    }
    return 0;
}

void solveSystem(vector<vector<double>> a, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, n, rankA, rankAug);

    if (solutionType == -1)
    {
        fout << "Solution Type: NO SOLUTION" << endl;
    }
    else if (solutionType == 1)
    {
        fout << "Solution Type: INFINITE SOLUTIONS" << endl;
    }
    else
    {
        fout << "Solution Type: UNIQUE SOLUTION" << endl;

        for (int i = 0; i < n; i++)
        {
            int maxRow = i;
            for (int k = i + 1; k < n; k++)
            {
                if (abs(a[k][i]) > abs(a[maxRow][i]))
                {
                    maxRow = k;
                }
            }
            swap(a[i], a[maxRow]);

            double pivot = a[i][i];
            for (int j = 0; j <= n; j++)
            {
                a[i][j] /= pivot;
            }

            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = a[k][i];
                    for (int j = 0; j <= n; j++)
                    {
                        a[k][j] -= factor * a[i][j];
                    }
                }
            }
        }

        fout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << "x" << i + 1 << " = " << a[i][n] << endl;
        }
    }

    fout << endl
         << endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << fixed << setprecision(6);
    fout << "Gauss-Jordan Elimination Method" << endl;
    fout << "================================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        solveSystem(a, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}

```

#### Gauss-Jordan Elimination Input

```
3

3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

3
1 2 3 6
2 4 6 12
1 1 1 3

3
1 2 3 6
2 4 6 12
1 2 3 10

```

#### Gauss-Jordan Elimination Output

```
Gauss-Jordan Elimination Method
================================

Problem 1
----------------------------------------
Solution Type: UNIQUE SOLUTION
Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000


Problem 2
----------------------------------------
Solution Type: INFINITE SOLUTIONS


Problem 3
----------------------------------------
Solution Type: NO SOLUTION



```

[⬆ Back to Table of Contents](#table-of-contents)

---

### LU Decomposition Method

#### LU Decomposition Theory

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

#### LU Decomposition Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int calculateRank(vector<vector<double>> mat, int rows, int cols)
{
    int rank = 0;
    for (int col = 0, row = 0; col < cols && row < rows; col++)
    {
        int maxRow = row;
        for (int k = row + 1; k < rows; k++)
        {
            if (abs(mat[k][col]) > abs(mat[maxRow][col]))
            {
                maxRow = k;
            }
        }

        if (abs(mat[maxRow][col]) < EPS)
        {
            continue;
        }

        swap(mat[row], mat[maxRow]);

        for (int k = row + 1; k < rows; k++)
        {
            double factor = mat[k][col] / mat[row][col];
            for (int j = col; j < cols; j++)
            {
                mat[k][j] -= factor * mat[row][j];
            }
        }
        rank++;
        row++;
    }
    return rank;
}

int checkSolutionType(vector<vector<double>> &A, vector<double> &b, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> augMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augMatrix[i][j] = A[i][j];
        }
        augMatrix[i][n] = b[i];
    }

    rankA = calculateRank(A, n, n);
    rankAug = calculateRank(augMatrix, n, n + 1);

    if (rankA < rankAug)
    {
        return -1;
    }
    else if (rankA < n)
    {
        return 1;
    }
    return 0;
}

void solveSystem(vector<vector<double>> a, vector<double> b, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, b, n, rankA, rankAug);

    if (solutionType == -1)
    {
        fout << "Solution Type: NO SOLUTION" << endl;
    }
    else if (solutionType == 1)
    {
        fout << "Solution Type: INFINITE SOLUTIONS" << endl;
    }
    else
    {
        fout << "Solution Type: UNIQUE SOLUTION" << endl;

        vector<vector<double>> L(n, vector<double>(n, 0));
        vector<vector<double>> U(n, vector<double>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                U[i][j] = a[i][j];
                for (int k = 0; k < i; k++)
                {
                    U[i][j] -= L[i][k] * U[k][j];
                }
            }

            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    L[i][i] = 1;
                }
                else
                {
                    L[j][i] = a[j][i];
                    for (int k = 0; k < i; k++)
                    {
                        L[j][i] -= L[j][k] * U[k][i];
                    }
                    L[j][i] /= U[i][i];
                }
            }
        }

        vector<double> y(n);
        for (int i = 0; i < n; i++)
        {
            y[i] = b[i];
            for (int j = 0; j < i; j++)
            {
                y[i] -= L[i][j] * y[j];
            }
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = y[i];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= U[i][j] * x[j];
            }
            x[i] /= U[i][i];
        }

        fout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << "x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fout << endl
         << endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << fixed << setprecision(6);
    fout << "LU Decomposition Method" << endl;
    fout << "=======================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<double> b(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            fin >> b[i];
        }

        solveSystem(a, b, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}

```

#### LU Decomposition Input

```
3

3
2 1 -1
-3 -1 2
-2 1 2
8 -11 -3

3
1 2 3
2 4 6
1 1 1
6 12 3

3
1 2 3
2 4 6
1 2 3
6 12 10

```

#### LU Decomposition Output

```
LU Decomposition Method
=======================

Problem 1
----------------------------------------
Solution Type: UNIQUE SOLUTION
Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000


Problem 2
----------------------------------------
Solution Type: INFINITE SOLUTIONS


Problem 3
----------------------------------------
Solution Type: NO SOLUTION



```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Matrix Inversion Method

#### Matrix Inversion Theory

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

#### Matrix Inversion Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

double determinant(vector<vector<double>> &A, int n)
{
    if (n == 1)
    {
        return A[0][0];
    }
    double detA = 0;
    vector<vector<double>> minor_mat(n - 1, vector<double>(n - 1));
    int sign = 1;
    for (int col = 0; col < n; col++)
    {
        int minor_row = 0;
        for (int row = 1; row < n; row++)
        {
            int minor_col = 0;
            for (int j = 0; j < n; j++)
            {
                if (col == j)
                    continue;
                minor_mat[minor_row][minor_col] = A[row][j];
                minor_col++;
            }
            minor_row++;
        }
        detA += sign * A[0][col] * determinant(minor_mat, n - 1);
        sign = -sign;
    }
    return detA;
}

vector<vector<double>> cofactor(vector<vector<double>> &A, int n)
{
    vector<vector<double>> co_mat(n, vector<double>(n));
    vector<vector<double>> minor_mat(n - 1, vector<double>(n - 1));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int minor_row = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == row)
                    continue;
                int minor_col = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == col)
                        continue;
                    minor_mat[minor_row][minor_col] = A[i][j];
                    minor_col++;
                }
                minor_row++;
            }
            int sign = ((row + col) % 2 == 0) ? 1 : -1;
            co_mat[row][col] = sign * determinant(minor_mat, n - 1);
        }
    }
    return co_mat;
}

vector<vector<double>> transpose(vector<vector<double>> &A, int n)
{
    vector<vector<double>> transposed(n, vector<double>(n));
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            transposed[col][row] = A[row][col];
    return transposed;
}

int calculateRank(vector<vector<double>> mat, int rows, int cols)
{
    int rank = 0;
    for (int col = 0, row = 0; col < cols && row < rows; col++)
    {
        int maxRow = row;
        for (int k = row + 1; k < rows; k++)
        {
            if (abs(mat[k][col]) > abs(mat[maxRow][col]))
            {
                maxRow = k;
            }
        }

        if (abs(mat[maxRow][col]) < EPS)
        {
            continue;
        }

        swap(mat[row], mat[maxRow]);

        for (int k = row + 1; k < rows; k++)
        {
            double factor = mat[k][col] / mat[row][col];
            for (int j = col; j < cols; j++)
            {
                mat[k][j] -= factor * mat[row][j];
            }
        }
        rank++;
        row++;
    }
    return rank;
}

int checkSolutionType(vector<vector<double>> &A, vector<double> &b, int n, int &rankA, int &rankAug)
{
    vector<vector<double>> augMatrix(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augMatrix[i][j] = A[i][j];
        }
        augMatrix[i][n] = b[i];
    }

    rankA = calculateRank(A, n, n);
    rankAug = calculateRank(augMatrix, n, n + 1);

    if (rankA < rankAug)
    {
        return -1;
    }
    else if (rankA < n)
    {
        return 1;
    }
    return 0;
}

void solveSystem(vector<vector<double>> a, vector<double> b, int n, int problemNo, ofstream &fout)
{
    fout << "Problem " << problemNo << endl;
    fout << string(40, '-') << endl;

    int rankA, rankAug;
    int solutionType = checkSolutionType(a, b, n, rankA, rankAug);

    double detA = determinant(a, n);
    fout << "Determinant of A = " << detA << endl;

    if (abs(detA) < EPS)
    {
        fout << "Matrix is NOT INVERTIBLE" << endl;
    }
    else
    {
        fout << "Matrix is INVERTIBLE" << endl;
    }

    if (solutionType == -1)
    {
        fout << "Solution Type: NO SOLUTION" << endl;
    }
    else if (solutionType == 1)
    {
        fout << "Solution Type: INFINITE SOLUTIONS" << endl;
    }
    else
    {
        fout << "Solution Type: UNIQUE SOLUTION" << endl;

        vector<vector<double>> co_mat = cofactor(a, n);
        vector<vector<double>> adj = transpose(co_mat, n);

        vector<vector<double>> inverse(n, vector<double>(n));
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                inverse[row][col] = adj[row][col] / detA;

        vector<double> x(n, 0);
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                x[row] += inverse[row][col] * b[col];

        fout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            fout << "x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fout << endl
         << endl;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << fixed << setprecision(6);
    fout << "Matrix Inversion Method" << endl;
    fout << "=======================" << endl
         << endl;

    int t;
    fin >> t;

    for (int p = 1; p <= t; p++)
    {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<double> b(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            fin >> b[i];
        }

        solveSystem(a, b, n, p, fout);
    }

    fin.close();
    fout.close();

    return 0;
}

```

#### Matrix Inversion Input

```
3

3
2 1 -1
-3 -1 2
-2 1 2
8 -11 -3

3
1 2 3
2 4 6
1 1 1
6 12 3

3
1 2 3
2 4 6
1 2 3
6 12 10

```

#### Matrix Inversion Output

```
Matrix Inversion Method
=======================

Problem 1
----------------------------------------
Determinant of A = -1.000000
Matrix is INVERTIBLE
Solution Type: UNIQUE SOLUTION
Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000


Problem 2
----------------------------------------
Determinant of A = 0.000000
Matrix is NOT INVERTIBLE
Solution Type: INFINITE SOLUTIONS


Problem 3
----------------------------------------
Determinant of A = 0.000000
Matrix is NOT INVERTIBLE
Solution Type: NO SOLUTION



```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Solution of Non-Linear Equations

### Bisection Method

#### Bisection Theory



# Bisection Method

The Bisection Method is a root-finding algorithm that repeatedly bisects an interval and selects a subinterval in which a root must lie.

## Conditions
- The function f(x) must be continuous on the interval [a, b]
- f(a) and f(b) must have opposite signs, i.e., f(a) × f(b) < 0

## Algorithm
1. Start with interval [a, b] where f(a) × f(b) < 0
2. Calculate midpoint: mid = (a + b) / 2
3. If f(mid) = 0, mid is the root
4. If f(a) × f(mid) < 0, root lies in [a, mid], set b = mid
5. Otherwise, root lies in [mid, b], set a = mid
6. Repeat until |f(mid)| < tolerance

## Advantages
- Always converges if conditions are met
- Simple to implement

## Disadvantages
- Slow convergence compared to Newton-Raphson
- Requires initial bracket with sign change



#### Bisection Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double x, vector<double>& coef)
{
    double result = 0;
    int n = coef.size();
    for(int i = 0; i < n; i++)
    {
        result += coef[i] * pow(x, n - 1 - i);
    }
    return result;
}

void bisection(double a, double b, double tol, vector<double>& coef)
{
    int iteration = 0;
    double mid;
    
    if(f(a, coef) * f(b, coef) > 0)
    {
        return;
    }
    
    while(true)
    {
        iteration++;
        mid = (a + b) / 2.0;
        double fmid = f(mid, coef);
        
        if(fabs(fmid) < tol)
        {
            break;
        }
        if(f(a, coef) * fmid < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }
    fout << "Root = " << mid << " found in " << iteration << " iterations" << endl;
}

int main()
{
    ifstream fin("input.txt");
    fout.open("output.txt");
    
    int t;
    fin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        int degree;
        fin >> degree;
        
        vector<double> coef(degree + 1);
        for(int i = 0; i <= degree; i++)
        {
            fin >> coef[i];
        }
        
        double a, b, tol, steps;
        fin >> a >> b >> tol >> steps;
        
        fout << "Test Case " << tc << ":" << endl;
        fout << "Polynomial: ";
        for(int i = 0; i <= degree; i++)
        {
            if(i > 0 && coef[i] >= 0) fout << "+";
            fout << coef[i];
            if(degree - i > 0) fout << "x^" << degree - i << " ";
        }
        fout << endl;
        fout << "Interval: [" << a << ", " << b << "]" << endl;
        fout << "Tolerance: " << tol << endl;
        fout << "Step size: " << steps << endl;
        
        double x1 = a;
        double x2 = a + steps;
        bool found = false;
        
        while(x2 <= b)
        {
            double f1 = f(x1, coef);
            double f2 = f(x2, coef);
            if(f1 * f2 < 0)
            {
                found = true;
                bisection(x1, x2, tol, coef);
            }
            x1 = x2;
            x2 = x2 + steps;
        }
        
        if(!found)
        {
            fout << "No Solution found in the given interval" << endl;
        }
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}

```

#### Bisection Input

```
2
3
1 -6 11 -6
0 4 0.0001 0.5
2
1 0 1
-5 5 0.0001 0.5

```

#### Bisection Output

```
Test Case 1:
Polynomial: 1x^3 -6x^2 +11x^1 -6
Interval: [0, 4]
Tolerance: 0.0001
Step size: 0.5
Root = 1.00006 found in 13 iterations
Root = 2.00006 found in 13 iterations
Root = 2.99994 found in 13 iterations

Test Case 2:
Polynomial: 1x^2 +0x^1 +1
Interval: [-5, 5]
Tolerance: 0.0001
Step size: 0.5
No Solution found in the given interval

```

[⬆ Back to Table of Contents](#table-of-contents)

---

### False Position Method

#### False Position Theory

The False Position Method is a root-finding algorithm that uses linear interpolation to find successively better approximations to the roots of a function.

## Conditions
- The function f(x) must be continuous on the interval [a, b]
- f(a) and f(b) must have opposite signs, i.e., f(a) × f(b) < 0

## Algorithm
1. Start with interval [a, b] where f(a) × f(b) < 0
2. Calculate: c = (a × f(b) - b × f(a)) / (f(b) - f(a))
3. If f(c) ≈ 0, c is the root
4. If f(a) × f(c) < 0, root lies in [a, c], set b = c
5. Otherwise, root lies in [c, b], set a = c
6. Repeat until |f(c)| < tolerance

## Formula
c = (a × f(b) - b × f(a)) / (f(b) - f(a))

## Convergence
- Convergence is guaranteed but may be slow for certain functions
- One endpoint may remain fixed (unlike Bisection)

## Advantages
- Always converges if conditions are met
- Faster than Bisection in most cases

## Disadvantages
- May converge slowly when one endpoint stays fixed
- Requires initial bracket with sign change

#### False Position Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");
vector<double> coef;
int degree;

double f(double x)
{
    double result = 0;
    for(int i = 0; i <= degree; i++)
    {
        result += coef[i] * pow(x, i);
    }
    return result;
}

void false_position(double a, double b, double e)
{
    int iteration = 0;
    double mid;
    if(f(a) * f(b) > 0)
    {
        return;
    }
    while(true)
    {
        iteration++;
        mid = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
        double fmid = f(mid);
        if(fabs(fmid) < e)
        {
            break;
        }
        if(f(a) * f(mid) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }
    fout << "Root=" << mid << " in iterations=" << iteration << endl;
}

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        fin >> degree;
        coef.clear();
        coef.resize(degree + 1);
        
        for(int i = degree; i >= 0; i--)
        {
            fin >> coef[i];
        }
        
        double a, b, steps, E;
        fin >> a >> b >> steps >> E;
        
        fout << "Test case=" << tc << endl;
        fout << fixed << setprecision(6);
        
        double x1 = a;
        double x2 = a + steps;
        bool found = false;
        
        while(x2 <= b)
        {
            if(fabs(f(x1)) < E)
            {
                fout << "Root=" << x1 << " in iterations=0" << endl;
                found = true;
            }
            else if(f(x1) * f(x2) < 0)
            {
                false_position(x1, x2, E);
                found = true;
            }
            x1 = x2;
            x2 = x2 + steps;
        }
        if(fabs(f(x1)) < E)
        {
            fout << "Root=" << x1 << " in iterations=0" << endl;
            found = true;
        }
        
        if(!found)
        {
            fout << "No root found in given interval" << endl;
        }
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}

```

#### False Position Input

```
3
3
1 -6 11 -6
0 4 0.5 1e-5
4
1 -3 2 -6 0
1 3 0.5 1e-4
3
1 -6 11 -11
0 4 0.5 1e-5

```

#### False Position Output

```
Test case=1
Root=1.000000 in iterations=0
Root=2.000000 in iterations=0
Root=3.000000 in iterations=1
Root=3.000000 in iterations=0

Test case=2
Root=3.000000 in iterations=1
Root=3.000000 in iterations=0

Test case=3
Root=3.904161 in iterations=5


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Newton-Raphson Method

#### Newton-Raphson Theory

The Newton-Raphson Method is a powerful root-finding algorithm that uses the derivative of a function to find successively better approximations to the roots.

## Conditions
- The function f(x) must be differentiable
- The derivative f'(x) should not be zero at or near the root
- Initial guess should be reasonably close to the actual root

## Algorithm
1. Start with an initial guess x₀
2. Calculate: x_{n+1} = x_n - f(x_n) / f'(x_n)
3. Repeat until |x_{n+1} - x_n| < tolerance

## Formula
x_{n+1} = x_n - f(x_n) / f'(x_n)

## Convergence
- Quadratic convergence (order 2)
- Very fast when initial guess is close to root
- May fail if f'(x) = 0

## Advantages
- Very fast convergence (quadratic)
- Only requires one initial guess

## Disadvantages
- Requires derivative calculation
- May diverge if initial guess is far from root
- Fails when derivative is zero

#### Newton-Raphson Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double a, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i >= 0; i--)
    {
        res += coefficient[i] * pow(a, i);
    }
    return res;
}

double df(double a, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i > 0; i--)
    {
        res += i * coefficient[i] * pow(a, i - 1);
    }
    return res;
}

void newton_raphson(double a, double e, vector<double>& coefficient)
{
    int iteration = 0;
    double x = a;

    while(true)
    {
        double fx = f(x, coefficient);
        double dfx = df(x, coefficient);

        if(fabs(dfx) < 1e-12)
        {
            return;
        }

        double xnew = x - (fx / dfx);
        iteration++;

        if(fabs(xnew - x) < e)
        {
            fout << "Root found: " << xnew << endl;
            break;
        }

        if(iteration > 100)
        {
            break;
        }

        x = xnew;
    }
}

int main()
{
    ifstream fin("input.txt");
    fout.open("output.txt");

    int t;
    fin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        int degree;
        fin >> degree;

        vector<double> coefficient(degree + 1);
        for(int i = degree; i >= 0; i--)
        {
            fin >> coefficient[i];
        }

        double steps, E;
        fin >> steps >> E;

        double amax = 0;
        for(int i = 0; i < degree; i++)
        {
            amax = max(amax, fabs(coefficient[i] / coefficient[degree]));
        }

        double xmax = 1 + amax;
        double x1 = -xmax, x2 = xmax;

        fout << "Test case=" << tc << endl;
        fout << "Polynomial: ";
        for(int i = degree; i >= 0; i--)
        {
            if(i < degree && coefficient[i] >= 0) fout << "+";
            fout << coefficient[i];
            if(i > 0) fout << "x^" << i << " ";
        }
        fout << endl;
        fout << "Search Interval: [" << x1 << ", " << x2 << "]" << endl;
        fout << "Tolerance: " << E << endl;
        fout << endl;

        double a = x1, b = x1 + steps;
        bool found = false;

        while(b <= x2)
        {
            double x0 = (a + b) / 2.0;

            if(fabs(f(a, coefficient)) < E)
            {
                fout << "Root found: " << a << endl;
                found = true;
            }
            else if((f(a, coefficient) * f(b, coefficient)) < 0)
            {
                found = true;
                newton_raphson(x0, E, coefficient);
            }
            a = b;
            b += steps;
        }

        if(!found)
        {
            fout << "No Solution found in the given interval" << endl;
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

```

#### Newton-Raphson Input

```
2
3
1 -6 11 -6
0.45 0.001
2
1 0 1
0.5 0.001

```

#### Newton-Raphson Output

```
Test case=1
Polynomial: 1x^3 -6x^2 +11x^1 -6
Search Interval: [-12, 12]
Tolerance: 0.001

Root found: 1
Root found: 2
Root found: 3

Test case=2
Polynomial: 1x^2 +0x^1 +1
Search Interval: [-2, 2]
Tolerance: 0.001

No Solution found in the given interval


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Secant Method

#### Secant Theory

The Secant Method is a root-finding algorithm that uses a succession of roots of secant lines to approximate a root of a function. It does not require the derivative of the function.

## Conditions
- The function should be continuous near the root
- Two initial guesses x0 and x1 are required
- f(x0) and f(x1) should not be equal

## Algorithm
1. Start with two initial guesses x0 and x1
2. Calculate: x_{n+1} = x_n - f(x_n) × (x_n - x_{n-1}) / (f(x_n) - f(x_{n-1}))
3. Repeat until convergence

## Formula
x_{n+1} = x_n - f(x_n) × (x_n - x_{n-1}) / (f(x_n) - f(x_{n-1}))

## Convergence
- Order of convergence: approximately 1.618 (golden ratio)
- Faster than Bisection but may not always converge

## Advantages
- Does not require derivative calculation
- Faster than Bisection method

## Disadvantages
- May not always converge
- Requires two initial guesses
- Can fail if f(x1) ≈ f(x0)

#### Secant Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout;

double f(double x, vector<double>& coefficient)
{
    int degree = coefficient.size() - 1;
    double res = 0;
    for(int i = degree; i >= 0; i--)
    {
        res += coefficient[i] * pow(x, i);
    }
    return res;
}

void secant(double x0, double x1, double tol, vector<double>& coefficient)
{
    int iteration = 0;
    double x_new;

    while(true)
    {
        iteration++;
        double fx1 = f(x1, coefficient);
        double fx0 = f(x0, coefficient);

        if(fabs(fx1 - fx0) < 1e-12)
        {
            return;
        }

        x_new = x1 - ((x1 - x0) / (fx1 - fx0)) * fx1;

        if(fabs(x_new) > 1e-12 && fabs((x_new - x1) / x_new) < tol)
        {
            break;
        }

        if(iteration > 100)
        {
            break;
        }

        x0 = x1;
        x1 = x_new;
    }

    fout << "Root found: " << x_new << endl;
}

int main()
{
    ifstream fin("input.txt");
    fout.open("output.txt");

    int t;
    fin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        int degree;
        fin >> degree;

        vector<double> coefficient(degree + 1);
        for(int i = degree; i >= 0; i--)
        {
            fin >> coefficient[i];
        }

        double tol;
        fin >> tol;

        fout << "Test case=" << tc << endl;
        fout << "Polynomial: ";
        for(int i = degree; i >= 0; i--)
        {
            if(i < degree && coefficient[i] >= 0) fout << "+";
            fout << coefficient[i];
            if(i > 0) fout << "x^" << i << " ";
        }
        fout << endl;
        fout << "Tolerance: " << tol << endl;
        fout << endl;

        bool found = false;
        for(double x = -10.0; x <= 10.0; x += 0.1)
        {
            if(fabs(f(x, coefficient)) < tol)
            {
                fout << "Root found: " << x << endl;
                found = true;
            }
            else if(f(x, coefficient) * f(x + 0.1, coefficient) < 0)
            {
                found = true;
                secant(x, x + 0.1, tol, coefficient);
            }
        }

        if(!found)
        {
            fout << "No Solution found in the given interval" << endl;
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

```

#### Secant Input

```
3
3
1 -5 11 -6
0.00001
2
1 0 1
0.00001
2
1 6 1
0.00001

```

#### Secant Output

```
Test case=1
Polynomial: 1x^3 -5x^2 +11x^1 -6
Tolerance: 1e-005

Root found: 0.777505

Test case=2
Polynomial: 1x^2 +0x^1 +1
Tolerance: 1e-005

No Solution found in the given interval

Test case=3
Polynomial: 1x^2 +6x^1 +1
Tolerance: 1e-005

Root found: -5.82843
Root found: -0.171573


```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Interpolation

### Divided Difference Method

#### Divided Difference Theory

## Theory

Newton's Divided Difference method constructs an interpolating polynomial using divided differences. Given n data points, it builds a polynomial of degree at most n-1 that passes through all the given points.

The divided differences are defined recursively:

$$f[x_i] = f(x_i) = y_i$$

$$f[x_i, x_{i+1}] = \frac{f[x_{i+1}] - f[x_i]}{x_{i+1} - x_i}$$

$$f[x_i, x_{i+1}, ..., x_{i+k}] = \frac{f[x_{i+1}, ..., x_{i+k}] - f[x_i, ..., x_{i+k-1}]}{x_{i+k} - x_i}$$

## Formula

The Newton's Divided Difference interpolating polynomial is:

$$P(x) = f[x_0] + f[x_0, x_1](x - x_0) + f[x_0, x_1, x_2](x - x_0)(x - x_1) + ... + f[x_0, x_1, ..., x_{n-1}](x - x_0)(x - x_1)...(x - x_{n-2})$$


## Preconditions

- At least 2 data points required
- All x values must be distinct

#### Divided Difference Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    fout << fixed << setprecision(6);
    
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        fin >> n;
        
        fout << "Test case " << tc << ":" << endl;
        
        if(n < 2)
        {
            fout << "Error: At least 2 data points are required for interpolation." << endl;
            fout << endl;
            continue;
        }
        
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++)
            fin >> x[i];
        
        for(int i = 0; i < n; i++)
            fin >> y[i];
        
        bool hasDuplicate = false;
        for(int i = 0; i < n && !hasDuplicate; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(abs(x[i] - x[j]) < 1e-9)
                {
                    hasDuplicate = true;
                    break;
                }
            }
        }
        
        if(hasDuplicate)
        {
            fout << "Error: Duplicate x values found. All x values must be distinct." << endl;
            fout << endl;
            double xp;
            fin >> xp;
            continue;
        }
        
        double xp;
        fin >> xp;
        
        vector<vector<double>> table(n, vector<double>(n, 0));
        
        for(int i = 0; i < n; i++)
            table[i][0] = y[i];
        
        for(int j = 1; j < n; j++)
        {
            for(int i = 0; i < n - j; i++)
            {
                table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
            }
        }
        
        double result = table[0][0];
        double term = 1.0;
        
        for(int i = 1; i < n; i++)
        {
            term *= (xp - x[i - 1]);
            result += table[0][i] * term;
        }
        
        fout << "P(" << xp << ") = " << result << endl;
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}

```

#### Divided Difference Input

```
2
4
1 2 3 4
1 8 27 64
2.5
3
0 1 2
1 2 5
1.5

```

#### Divided Difference Output

```
Test case 1:
P(2.500000) = 15.625000

Test case 2:
P(1.500000) = 3.250000


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Newtons Forward Interpolation Method

#### Newtons Forward Interpolation Theory

## Theory

Newton's Forward Interpolation is a method used to find the value of a function at a point that lies within the range of given equally spaced data points. It is most accurate near the beginning of the data set.

## Difference Table Calculation

For a set of values (x₀, y₀), (x₁, y₁), ..., (xₙ, yₙ) where x values are equally spaced with interval h:

**First Forward Difference:**
Δy₀ = y₁ - y₀

**nth Forward Difference:**
Δⁿy₀ = Δⁿ⁻¹y₁ - Δⁿ⁻¹y₀

## Interpolation Formula

For a point x = x₀ + uh, where u = (x - x₀)/h:

**y(x) = y₀ + uΔy₀ + [u(u-1)/2!]Δ²y₀ + [u(u-1)(u-2)/3!]Δ³y₀ + ... + [u(u-1)...(u-n+1)/n!]Δⁿy₀**

## Applications

- Estimating unknown function values at intermediate points from tabulated data
- Computing missing values in experimental or observational datasets
- Predicting trends between known data points in scientific analysis

#### Newtons Forward Interpolation Code

```cpp
#include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int case_count = 1;
    while(cin >> n) {
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double h = x[1] - x[0];
        
        double p;
        cin >> p;
        
        double u = (p - x[0]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - j; i++) {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }
        
        double result = y[0];
        double u_term = 1.0;
        
        for(int i = 1; i < n; i++) {
            u_term *= (u - (i - 1));
            result += (u_term * diff[0][i]) / fact(i);
        }
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For x=" << p <<endl;
        cout << "Result: " << setprecision(6) << result << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Newtons Forward Interpolation Input

```
5
1 1
2 4
3 9
4 16
5 25
3.5
5
0 1
1 2.718282
2 7.389056
3 20.085537
4 54.598150
1.5

```

#### Newtons Forward Interpolation Output

```
Test case 1: 
For x=3.5
Result: 12.25

Test case 2: 
For x=1.5
Result: 4.57184


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Newtons Backward Interpolation Method

#### Newtons Backward Interpolation Theory

## Theory

Newton's Backward Interpolation is a method used to find the value of a function at a point that lies within the range of given equally spaced data points. It is most accurate near the end of the data set.

## Difference Table Calculation

For a set of values (x₀, y₀), (x₁, y₁), ..., (xₙ, yₙ) where x values are equally spaced with interval h:

**First Backward Difference:**
∇yₙ = yₙ - yₙ₋₁

**nth Backward Difference:**
∇ⁿyₙ = ∇ⁿ⁻¹yₙ - ∇ⁿ⁻¹yₙ₋₁

## Interpolation Formula

For a point x = xₙ + vh, where v = (x - xₙ)/h:

**y(x) = yₙ + v∇yₙ + [v(v+1)/2!]∇²yₙ + [v(v+1)(v+2)/3!]∇³yₙ + ... + [v(v+1)...(v+n-1)/n!]∇ⁿyₙ**

## Applications

- Estimating unknown function values at intermediate points from tabulated data
- Computing missing values in experimental or observational datasets
- Predicting trends between known data points in scientific analysis

#### Newtons Backward Interpolation Code

```cpp
#include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int case_count = 1;
    while(cin >> n) {
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double h = x[1] - x[0];
        
        double p;
        cin >> p;
        
        double v = (p - x[n-1]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = n - 1; i >= j; i--) {
                diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
            }
        }
        
        double result = y[n-1];
        double v_term = 1.0;
        
        for(int i = 1; i < n; i++) {
            v_term *= (v + (i - 1));
            result += (v_term * diff[n-1][i]) / fact(i);
        }
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For x=" << p <<endl;
        cout << "Result: " << setprecision(6) << result << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Newtons Backward Interpolation Input

```
5
1 1
2 4
3 9
4 16
5 25
4.5
5
0 1
1 2.718282
2 7.389056
3 20.085537
4 54.598150
3.5

```

#### Newtons Backward Interpolation Output

```
Test case 1: 
For x=4.5
Result: 20.25

Test case 2: 
For x=3.5
Result: 33.4124

```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Numerical Integration

### Simpsons One Third Rule Method

#### Simpsons One Third Rule Theory

## Theory

Simpson's 1/3 Rule is a numerical Numerical Integration technique that approximates the definite integral of a function by using quadratic polynomials. It is more accurate than the Trapezoidal Rule as it uses parabolic arcs instead of straight line segments.

## Mathematical Foundation

For a function f(x) to be integrated over the interval [a, b], Simpson's 1/3 Rule divides the interval into an even number of subintervals n (where n must be even).

The interval width h is given by:
**h = (b - a) / n**

## Formula

**∫[a to b] f(x)dx ≈ (h/3)[ (f(x₀)+f(xₙ)) + 4(f(x₁) + f(x₃) + ... + f(xₙ₋₁)) + 2(f(x₂) + f(x₄) + ... + f(xₙ₋₂))]**

Where:
- x₀ = a (starting point)
- xₙ = b (ending point)
- xᵢ = x₀ + i×h (intermediate points)

## Simplified Form

**I ≈ (h/3)[(y₀+yₙ) + 4∑(odd indices) + 2∑(even indices excluding first and last)]**

## Applications

- Computing areas under curves
- Evaluating definite integrals numerically
- Engineering problems involving work, volume, and other physical quantities
- Scientific computations requiring numerical Numerical Integration

#### Simpsons One Third Rule Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int case_count = 1;
    while(cin >> n) {
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double l, u;
        cin >> l >> u;
        
        double h = x[1] - x[0];
        
        double sum4 = 0.0;
        for(int i = 1; i < n-1; i += 2) {
            sum4 += y[i];
        }
        
        double sum2 = 0.0;
        for(int i = 2; i < n-1; i += 2) {
            sum2 += y[i];
        }
        
        double integral = (h / 3.0) * (y[0] + 4.0 * sum4 + 2.0 * sum2 + y[n-1]);
    
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "Numerical Integration from range (" << l << " to " << u << ")" << endl;
        cout << setprecision(6);
        cout << "Result : " << integral << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Simpsons One Third Rule Input

```
7
0 1
0.5 0.8
1 0.5
1.5 0.3
2 0.2
2.5 0.1
3 0.05
0 3

5
0 0
1 1
2 8
3 27
4 64
0 4

```

#### Simpsons One Third Rule Output

```
Test case 1: 
Numerical Integration from range (0 to 3)
Result : 1.20833

Test case 2: 
Numerical Integration from range (0 to 4)
Result : 64


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Simpsons Three Eighth Rule Method

#### Simpsons Three Eighth Rule Theory

## Theory

Simpson's 3/8 Rule is a numerical Numerical Integration technique that approximates the definite integral of a function by using cubic polynomials. It provides an alternative to Simpson's 1/3 Rule and is particularly useful when the number of intervals is a multiple of 3.

## Mathematical Foundation

For a function f(x) to be integrated over the interval [a, b], Simpson's 3/8 Rule divides the interval into subintervals where the number of intervals n must be a multiple of 3.

The interval width h is given by:
**h = (b - a) / n**

## Formula

**∫[a to b] f(x)dx ≈ (3h/8)[(f(x₀)+f(xₙ)) + 3(f(x₁) + f(x₂) + f(x₄) + f(x₅) + ...) + 2(f(x₃) + f(x₆) + ...)]**

Where:
- x₀ = a (starting point)
- xₙ = b (ending point)
- xᵢ = x₀ + i×h (intermediate points)

## Simplified Form

**I ≈ (3h/8)[(y₀+yₙ) + 3∑(non-multiples of 3) + 2∑(multiples of 3 excluding first and last)]**

## Applications

- Computing areas under curves
- Evaluating definite integrals numerically
- Engineering calculations requiring numerical Numerical Integration

#### Simpsons Three Eighth Rule Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int case_count = 1;
    while(cin >> n) {
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double l, u;
        cin >> l >> u;
        
        double h = x[1] - x[0];
        
        double sum3 = 0.0;
        for(int i = 1; i < n-1; i++) {
            if(i % 3 != 0) {
                sum3 += y[i];
            }
        }
        
        double sum2 = 0.0;
        for(int i = 3; i < n-1; i += 3) {
            sum2 += y[i];
        }
        
        double integral = (3.0 * h / 8.0) * (y[0] + 3.0 * sum3 + 2.0 * sum2 + y[n-1]);
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "Numerical Integration from range (" << l << " to " << u << ")" << endl;
        cout << setprecision(6);
        cout << "Result : " << integral << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Simpsons Three Eighth Rule Input

```
7
0 1
0.5 0.8
1 0.5
1.5 0.3
2 0.2
2.5 0.1
3 0.05
0 3

7
0 0
0.5 0.125
1 1
1.5 3.375
2 8
2.5 15.625
3 27
0 3

```

#### Simpsons Three Eighth Rule Output

```
Test case 1: 
Numerical Integration from range (0 to 3)
Result : 1.20938

Test case 2: 
Numerical Integration from range (0 to 3)
Result : 20.25


```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Numerical Differentiation

### Newtons Forward Difference Method

#### Newtons Forward Difference Theory

## Theory

Newton's Forward Difference Formula is a numerical Numerical Differentiation technique used to approximate derivatives when data points are equally spaced and the derivative is required near the beginning of the tabulated data.

## Difference Table Calculation

For a function y = f(x) with equally spaced data points x₀, x₁, x₂, ..., xₙ with spacing h, the forward differences are defined as:

**First Forward Difference:**
Δy₀ = y₁ - y₀

**Second Forward Difference:**
Δ²y₀ = Δy₁ - Δy₀

**nth Forward Difference:**
Δⁿy₀ = Δⁿ⁻¹y₁ - Δⁿ⁻¹y₀

## Newton's Forward Difference Interpolation Formula

For a point x = x₀ + uh, where u = (x - x₀)/h:

**f(x) = y₀ + uΔy₀ + [u(u-1)/2!]Δ²y₀ + [u(u-1)(u-2)/3!]Δ³y₀ + ...**

## First Derivative

Differentiating with respect to x:

**f'(x) = (1/h)[Δy₀ + [(2u-1)/2]Δ²y₀ + [(3u²-6u+2)/6]Δ³y₀ + [(4u³-18u²+22u-6)/24]Δ⁴y₀ + ...]**

## Second Derivative

**f''(x) = (1/h²)[Δ²y₀ + (u-1)Δ³y₀ + ((6u²-18u+11)/12)Δ⁴y₀ + ...]**

## Applications

- Approximating derivatives at the beginning of a data table
- Numerical solution of differential equations
- Data analysis and curve fitting

#### Newtons Forward Difference Code

```cpp
#include <bits/stdc++.h>
using namespace std;


long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int case_count = 1;
    while(cin >> n) {
    
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double h = x[1] - x[0];
        
        double p;
        cin >> p;
        
        double u = (p - x[0]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < n - j; i++) {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }
        
        double dy = 0;
        double d2y = 0;
        
        if(n >= 2) {
            dy += diff[0][1];
        }
        
        if(n >= 3) {
            double t2 = 2*u - 1;
            double t2_ = 2;
            
            dy += (diff[0][2] / fact(2)) * t2;
            d2y += (diff[0][2] / fact(2)) * t2_;
        }
        
        if(n >= 4) {
            double t3 = 3*u*u - 6*u + 2;
            double t3_ = 6*u - 6;
            
            dy += (diff[0][3] / fact(3)) * t3;
            d2y += (diff[0][3] / fact(3)) * t3_;
        }
        
        if(n >= 5) {
            double t4 = 4*pow(u, 3) - 18*u*u + 22*u - 6;
            double t4_ = 12*u*u - 36*u + 22;
            
            dy += (diff[0][4] / fact(4)) * t4;
            d2y += (diff[0][4] / fact(4)) * t4_;
        }
        
        if(n >= 6) {
            double t5 = 5*pow(u, 4) - 40*pow(u, 3) + 105*u*u - 100*u + 24;
            double t5_ = 20*pow(u, 3) - 120*u*u + 210*u - 100;
            
            dy += (diff[0][5] / fact(5)) * t5;
            d2y += (diff[0][5] / fact(5)) * t5_;
        }
        
        dy /= h;
        d2y /= (h * h);
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout << "For point x=" << p << endl;
        cout << setprecision(6);
        cout << "1st Derivative f'(x) = " << dy << endl;
        cout << "2nd Derivative f''(x) = " << d2y << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Newtons Forward Difference Input

```
5
1 1
2 4
3 9
4 16
5 25
1.5

5
0 1
1 2.71
2 7.38
3 20.08
4 54.59
0.5

```

#### Newtons Forward Difference Output

```
Test case 1: 
For point x=1.5
1st Derivative f'(x) = 3
2nd Derivative f''(x) = 2

Test case 2: 
For point x=0.5
1st Derivative f'(x) = 1.86167
2nd Derivative f''(x) = 2.96542


```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Newtons Backward Difference Method

#### Newtons Backward Difference Theory

## Theory

Newton's Backward Difference Formula is a numerical Numerical Differentiation technique used to approximate derivatives when data points are equally spaced and the derivative is required near the end of the tabulated data.

## Difference Table Calculation

For a function y = f(x) with equally spaced data points x₀, x₁, x₂, ..., xₙ with spacing h, the backward differences are defined as:

**First Backward Difference:**
∇yₙ = yₙ - yₙ₋₁

**Second Backward Difference:**
∇²yₙ = ∇yₙ - ∇yₙ₋₁

**nth Backward Difference:**
∇ⁿyₙ = ∇ⁿ⁻¹yₙ - ∇ⁿ⁻¹yₙ₋₁

## Newton's Backward Difference Interpolation Formula

For a point x = xₙ + vh, where v = (x - xₙ)/h:

**f(x) = yₙ + v∇yₙ + [v(v+1)/2!]∇²yₙ + [v(v+1)(v+2)/3!]∇³yₙ + ...**

## First Derivative

Differentiating with respect to x:

**f'(x) = (1/h)[∇yₙ + [(2v+1)/2]∇²yₙ + [(3v²+6v+2)/6]∇³yₙ + [(4v³+18v²+22v+6)/24]∇⁴yₙ + ...]**

## Second Derivative

**f''(x) = (1/h²)[∇²yₙ + (v+1)∇³yₙ + ((6v²+18v+11)/12)∇⁴yₙ + ...]**

## Applications

- Approximating derivatives at the end of a data table
- Numerical solution of differential equations
- Data analysis and curve fitting

#### Newtons Backward Difference Code

```cpp
#include <bits/stdc++.h>
using namespace std;


long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int case_count = 1;
    while(cin >> n) {
    
        vector<double> x(n), y(n);
        
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        
        double h = x[1] - x[0];
        
        double p;
        cin >> p;
        
        double v = (p - x[n-1]) / h;
        
        vector<vector<double>> diff(n, vector<double>(n));
        
        for(int i = 0; i < n; i++) {
            diff[i][0] = y[i];
        }
        
        for(int j = 1; j < n; j++) {
            for(int i = n - 1; i >= j; i--) {
                diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
            }
        }
        
        double dy = 0;
        double d2y = 0;
        
        if (n >= 2) {
            dy += diff[n-1][1]; 
        }
        
        if (n >= 3) {
            double t2 = 2*v + 1;
            double t2_ = 2;
            
            dy += (diff[n-1][2] / fact(2)) * t2;
            d2y += (diff[n-1][2] / fact(2)) * t2_;
        }
        
        if (n >= 4) {
            double t3 = 3*v*v + 6*v + 2;
            double t3_ = 6*v + 6;
            
            dy += (diff[n-1][3] / fact(3)) * t3;
            d2y += (diff[n-1][3] / fact(3)) * t3_;
        }
        
        if (n >= 5) {
            double t4 = 4*pow(v, 3) + 18*v*v + 22*v + 6;
            double t4_ = 12*v*v + 36*v + 22;
            
            dy += (diff[n-1][4] / fact(4)) * t4;
            d2y += (diff[n-1][4] / fact(4)) * t4_;
        }
        
        if (n >= 6) {
            double t5 = 5*pow(v, 4) + 40*pow(v, 3) + 105*v*v + 100*v + 24;
            double t5_ = 20*pow(v, 3) + 120*v*v + 210*v + 100;
            
            dy += (diff[n-1][5] / fact(5)) * t5;
            d2y += (diff[n-1][5] / fact(5)) * t5_;
        }

        dy /= h;
        d2y /= (h * h);
        
        cout << "Test case " << case_count++ << ": " << endl;
        cout<<"For point x="<<p<<endl;
        cout << setprecision(6);
        cout << "1st Derivative f'(x) = " << dy << endl;
        cout << "2nd Derivative f''(x) = " << d2y << endl;
        cout << endl;
    }
    
    return 0;
}

```

#### Newtons Backward Difference Input

```
5
1 1
2 4
3 9
4 16
5 25
4.5

5
0 1
1 2.71
2 7.38
3 20.08
4 54.59
4

```

#### Newtons Backward Difference Output

```
Test case 1: 
For point x=4.5
1st Derivative f'(x) = 9
2nd Derivative f''(x) = 2

Test case 2: 
For point x=4
1st Derivative f'(x) = 52.1858
2nd Derivative f''(x) = 43.5742


```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Regression

### Linear Regression Method

#### Linear Regression Theory

## Theory

Linear Regression is a method to find the best-fitting straight line through a set of data points. Given n points, we want to find a line $y = a + bx$ such that the sum of squared vertical distances from each point to the line is minimized. This is called the Least Squares Method.

The slope $b$ represents how much $y$ changes for a unit change in $x$. The intercept $a$ is the value of $y$ when $x = 0$.

## Model

$$y = a + bx$$

## Formulas

$$b = \frac{n \sum xy - \sum x \sum y}{n \sum x^2 - (\sum x)^2}$$

$$a = \frac{\sum y - b \sum x}{n}$$

#### Linear Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n;
    inFile >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a = (sum_y - b * sum_x) / n;

    double y_pred = a + b * x_pred;

    outFile << fixed << setprecision(6);
    outFile << "Linear Regression: y = a + bx" << endl;
    outFile << "n = " << n << endl;
    outFile << "a = " << a << endl;
    outFile << "b = " << b << endl;
    outFile << "For x = " << x_pred << ", y = " << y_pred << endl;

    inFile.close();
    outFile.close();

    return 0;
}

```

#### Linear Regression Input

```
5
1 2.1
2 3.9
3 6.2
4 7.8
5 10.1
6

```

#### Linear Regression Output

```
Linear Regression: y = a + bx
n = 5
a = 0.020000
b = 2.000000
For x = 6.000000, y = 12.020000

```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Polynomial Regression Method

#### Polynomial Regression Theory

## Theory

Polynomial Regression is used when the relationship between x and y is not linear but can be represented by a curve. We fit a polynomial of degree m to the data points.

To find the coefficients $a_0, a_1, \ldots, a_m$, we set up a system of $(m+1)$ equations called Normal Equations. The left matrix contains sums of powers of x, and the right side contains sums of $x^k \cdot y$. This system is then solved using Gaussian Elimination to get all coefficients.

## Model

$$y = a_0 + a_1x + a_2x^2 + \ldots + a_mx^m$$

## Normal Equations

For degree m polynomial with n data points:

$$\begin{bmatrix} n & \sum x & \sum x^2 & \cdots & \sum x^m \\\ \sum x & \sum x^2 & \sum x^3 & \cdots & \sum x^{m+1} \\\ \sum x^2 & \sum x^3 & \sum x^4 & \cdots & \sum x^{m+2} \\\ \vdots & \vdots & \vdots & \ddots & \vdots \\\ \sum x^m & \sum x^{m+1} & \sum x^{m+2} & \cdots & \sum x^{2m} \end{bmatrix} \begin{bmatrix} a_0 \\\ a_1 \\\ a_2 \\\ \vdots \\\ a_m \end{bmatrix} = \begin{bmatrix} \sum y \\\ \sum xy \\\ \sum x^2y \\\ \vdots \\\ \sum x^m y \end{bmatrix}$$

Solve using Gaussian Elimination.

#### Polynomial Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n, degree;
    inFile >> n >> degree;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    int m = degree + 1;
    vector<double> sumX(2 * degree + 1, 0);
    vector<double> sumXY(m, 0);

    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= 2 * degree; j++)
        {
            sumX[j] += xi;
            xi *= x[i];
        }
        xi = 1;
        for (int j = 0; j < m; j++)
        {
            sumXY[j] += xi * y[i];
            xi *= x[i];
        }
    }

    vector<vector<double>> A(m, vector<double>(m + 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = sumX[i + j];
        }
        A[i][m] = sumXY[i];
    }

    for (int i = 0; i < m; i++)
    {
        int maxRow = i;
        for (int k = i + 1; k < m; k++)
        {
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        }
        swap(A[i], A[maxRow]);

        for (int k = i + 1; k < m; k++)
        {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= m; j++)
            {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    vector<double> coef(m);
    for (int i = m - 1; i >= 0; i--)
    {
        coef[i] = A[i][m];
        for (int j = i + 1; j < m; j++)
        {
            coef[i] -= A[i][j] * coef[j];
        }
        coef[i] /= A[i][i];
    }

    double y_pred = 0, xi = 1;
    for (int i = 0; i < m; i++)
    {
        y_pred += coef[i] * xi;
        xi *= x_pred;
    }

    outFile << fixed << setprecision(6);
    outFile << "Polynomial Regression (degree " << degree << ")" << endl;
    outFile << "n = " << n << endl;
    for (int i = 0; i < m; i++)
    {
        outFile << "a" << i << " = " << coef[i] << endl;
    }
    outFile << "For x = " << x_pred << ", y = " << y_pred << endl;

    inFile.close();
    outFile.close();

    return 0;
}

```

#### Polynomial Regression Input

```
6 2
0 1.0
1 1.8
2 5.1
3 10.2
4 17.0
5 26.1
6

```

#### Polynomial Regression Output

```
Polynomial Regression (degree 2)
n = 6
a0 = 0.917857
a1 = 0.078929
a2 = 0.991071
For x = 6.000000, y = 37.070000

```

[⬆ Back to Table of Contents](#table-of-contents)

---

### Transcendental Regression Method

#### Transcendental Regression Theory

## Theory

Transcendental Regression is used when data follows exponential, power, or logarithmic patterns instead of a straight line.

The key idea is linearization: we transform the non-linear equation into a linear form using logarithms. After transformation, we apply the standard linear regression formulas to find the coefficients. Finally, we convert back to get the original parameters.

For example, $y = ae^{bx}$ becomes $\ln(y) = \ln(a) + bx$, which is linear in x and $\ln(y)$.

## Models

| Type | Model                | Transformation             |
| ---- | -------------------- | -------------------------- |
| 1    | $y = a \cdot e^{bx}$ | $Y = \ln(y)$, $X = x$      |
| 2    | $y = a \cdot x^b$    | $Y = \ln(y)$, $X = \ln(x)$ |
| 3    | $y = a + b\ln(x)$    | $Y = y$, $X = \ln(x)$      |

## Formulas (on transformed data)

$$b = \frac{n \sum XY - \sum X \sum Y}{n \sum X^2 - (\sum X)^2}$$

$$A = \frac{\sum Y - b \sum X}{n}$$

For Type 1 and 2: $a = e^A$

For Type 3: $a = A$

#### Transcendental Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n, type;
    inFile >> n >> type;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        inFile >> x[i] >> y[i];
    }

    double x_pred;
    inFile >> x_pred;

    vector<double> X(n), Y(n);

    if (type == 1)
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = x[i];
            Y[i] = log(y[i]);
        }
    }
    else if (type == 2)
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = log(y[i]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            X[i] = log(x[i]);
            Y[i] = y[i];
        }
    }

    double sum_X = 0, sum_Y = 0, sum_XY = 0, sum_X2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum_X += X[i];
        sum_Y += Y[i];
        sum_XY += X[i] * Y[i];
        sum_X2 += X[i] * X[i];
    }

    double B = (n * sum_XY - sum_X * sum_Y) / (n * sum_X2 - sum_X * sum_X);
    double A = (sum_Y - B * sum_X) / n;

    double a, b, y_predicted;

    outFile << fixed << setprecision(6);

    if (type == 1)
    {
        a = exp(A);
        b = B;
        y_predicted = a * exp(b * x_pred);
        outFile << "Exponential Regression: y = a * e^(bx)" << endl;
    }
    else if (type == 2)
    {
        a = exp(A);
        b = B;
        y_predicted = a * pow(x_pred, b);
        outFile << "Power Regression: y = a * x^b" << endl;
    }
    else
    {
        a = A;
        b = B;
        y_predicted = a + b * log(x_pred);
        outFile << "Logarithmic Regression: y = a + b*ln(x)" << endl;
    }

    outFile << "n = " << n << endl;
    outFile << "a = " << a << endl;
    outFile << "b = " << b << endl;
    outFile << "For x = " << x_pred << ", y = " << y_predicted << endl;

    inFile.close();
    outFile.close();

    return 0;
}

```

#### Transcendental Regression Input

```
5 1
1 2.7
2 7.4
3 20.1
4 54.6
5 148.4
6

```

#### Transcendental Regression Output

```
Exponential Regression: y = a * e^(bx)
n = 5
a = 0.999102
b = 1.000185
For x = 6.000000, y = 404.052553

```

[⬆ Back to Table of Contents](#table-of-contents)

---

## Ordinary Differential Equations

### Runge-Kutta 4th Order (RK4) Method

#### Runge-Kutta 4th Order (RK4) Theory

## Theory

The Runge-Kutta 4th Order method is a numerical technique for solving first-order ordinary differential equations of the form:

$$\frac{dy}{dx} = f(x, y) \quad \text{with} \quad y(x_0) = y_0$$

The method computes four slopes at different points within each step:

- $k_1$ is the slope at the beginning of the interval
- $k_2$ is the slope at the midpoint, using $k_1$ to estimate $y$
- $k_3$ is the slope at the midpoint, using $k_2$ to estimate $y$
- $k_4$ is the slope at the end of the interval, using $k_3$ to estimate $y$

The final value is calculated using a weighted average of these slopes with weights 1, 2, 2, and 1 respectively.

## Formula

Given step size $h$:

$$k_1 = h \cdot f(x_n, y_n)$$

$$k_2 = h \cdot f\left(x_n + \frac{h}{2}, y_n + \frac{k_1}{2}\right)$$

$$k_3 = h \cdot f\left(x_n + \frac{h}{2}, y_n + \frac{k_2}{2}\right)$$

$$k_4 = h \cdot f(x_n + h, y_n + k_3)$$

$$y_{n+1} = y_n + \frac{1}{6}(k_1 + 2k_2 + 2k_3 + k_4)$$

$$x_{n+1} = x_n + h$$

#### Runge-Kutta 4th Order (RK4) Code

```cpp
#include<bits/stdc++.h>
using namespace std;

ofstream fout("output.txt");

double f(double x, double y)
{
    return x + y;
}

int main()
{
    ifstream fin("input.txt");
    
    int t;
    fin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        double x0, y0, h, Xn;
        fin >> x0 >> y0 >> h >> Xn;
        
        fout << "Test case=" << tc << endl;
        fout << fixed << setprecision(6);
        
        double x = x0;
        double y = y0;
        
        while(x + 1e-12 < Xn)
        {
            double k1 = h * f(x, y);
            double k2 = h * f(x + h/2, y + k1/2);
            double k3 = h * f(x + h/2, y + k2/2);
            double k4 = h * f(x + h, y + k3);
            
            y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
            x = x + h;
        }
        
        fout << "At x=" << x << ", y=" << y << endl;
        fout << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}

```

#### Runge-Kutta 4th Order (RK4) Input

```
2
0 1 0.1 0.5
0 1 0.2 1.0

```

#### Runge-Kutta 4th Order (RK4) Output

```
Test case=1
At x=0.500000, y=1.797441

Test case=2
At x=1.000000, y=3.436502

```

[⬆ Back to Table of Contents](#table-of-contents)


## 👥 Authors

- **Md. Sabbir Hossain** (Roll: 2207102)  
  GitHub: https://github.com/SABBIR-H0SSAIN

- **Md. Siam Kabir** (Roll: 2207106)  
  GitHub: https://github.com/Siam-Kabir-23

- **Md. Masumur Rahman Fokrul** (Roll: 2207114)  
  GitHub: https://github.com/Masum1601
