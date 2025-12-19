# Simpson's 1/3 Rule

## Theory

Simpson's 1/3 Rule is a numerical integration technique that approximates the definite integral of a function by using quadratic polynomials. It is more accurate than the Trapezoidal Rule as it uses parabolic arcs instead of straight line segments.

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
- Scientific computations requiring numerical integration

