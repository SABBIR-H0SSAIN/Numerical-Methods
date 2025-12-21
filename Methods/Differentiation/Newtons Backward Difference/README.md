# Newton's Backward Difference Formula

## Theory

Newton's Backward Difference Formula is a numerical differentiation technique used to approximate derivatives when data points are equally spaced and the derivative is required near the end of the tabulated data.

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
