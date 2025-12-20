# Transcendental Regression

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
