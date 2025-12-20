# False Position Method (Regula Falsi)

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