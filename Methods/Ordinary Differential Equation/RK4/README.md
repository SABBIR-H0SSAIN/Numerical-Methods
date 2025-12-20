# Runge-Kutta 4th Order Method (RK4)

## Theory

The Runge-Kutta 4th Order method is a numerical technique for solving first-order ordinary differential equations of the form:

$$\frac{dy}{dx} = f(x, y) \quad \text{with} \quad y(x_0) = y_0$$

The method computes four slopes at different points within each step:

- $k_1$ is the slope at the beginning of the interval
- $k_2$ is the slope at the midpoint, using $k_1$ to estimate $y$
- $k_3$ is the slope at the midpoint, using $k_2$ to estimate $y$
- $k_4$ is the slope at the end of the interval, using $k_3$ to estimate $y$

The final value is calculated using a weighted average of these slopes with weights 1, 2, 2, and 1 respectively.

## Formula

Given step size $h$:

$$k_1 = h \cdot f(x_n, y_n)$$

$$k_2 = h \cdot f\left(x_n + \frac{h}{2}, y_n + \frac{k_1}{2}\right)$$

$$k_3 = h \cdot f\left(x_n + \frac{h}{2}, y_n + \frac{k_2}{2}\right)$$

$$k_4 = h \cdot f(x_n + h, y_n + k_3)$$

$$y_{n+1} = y_n + \frac{1}{6}(k_1 + 2k_2 + 2k_3 + k_4)$$

$$x_{n+1} = x_n + h$$
