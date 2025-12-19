# Solution of Non-Linear Equations

This folder contains implementations of numerical methods for finding roots of non-linear equations.

## Methods Included

| Method | Folder | Description |
|--------|--------|-------------|
| Bisection | [Bisection](Bisection/) | Bracketing method with guaranteed convergence |
| False Position | [FalsePosition](FalsePosition/) | Regula Falsi method using linear interpolation |
| Secant | [Secant](Secant/) | Open method without derivative requirement |
| Newton-Raphson | [NewtonRaphson](NewtonRaphson/) | Fast convergence using derivatives |

## Comparison

| Method | Convergence | Derivative Required | Bracket Required |
|--------|-------------|---------------------|------------------|
| Bisection | Linear (slow) | No | Yes |
| False Position | Superlinear | No | Yes |
| Secant | ~1.618 order | No | No |
| Newton-Raphson | Quadratic (fast) | Yes | No |

## Input Format

All methods use a polynomial input format:
```
degree
coef[0] coef[1] ... coef[degree]
<method-specific parameters>
```

Coefficients are from highest to lowest degree.

Example for f(x) = x³ - 6x² + 11x - 6:
```
3
1 -6 11 -6
```

## How to Use

1. Navigate to the specific method folder
2. Edit `input.txt` with your polynomial and parameters
3. Compile: `g++ <method>.cpp -o <method>`
4. Run: `./<method>`
5. Check results in `output.txt`
