

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

