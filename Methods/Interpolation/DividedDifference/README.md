# Newton's Divided Difference Interpolation

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
