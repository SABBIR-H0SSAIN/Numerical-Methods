# Newton-Raphson Method

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
