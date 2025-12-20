# Secant Method

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
