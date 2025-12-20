# Simpson's 3/8 Rule

## Theory

Simpson's 3/8 Rule is a numerical integration technique that approximates the definite integral of a function by using cubic polynomials. It provides an alternative to Simpson's 1/3 Rule and is particularly useful when the number of intervals is a multiple of 3.

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
- Engineering calculations requiring numerical integration


