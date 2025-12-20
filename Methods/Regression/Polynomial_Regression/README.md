# Polynomial Regression

## Theory

Polynomial Regression is used when the relationship between x and y is not linear but can be represented by a curve. We fit a polynomial of degree m to the data points.

To find the coefficients $a_0, a_1, \ldots, a_m$, we set up a system of $(m+1)$ equations called Normal Equations. The left matrix contains sums of powers of x, and the right side contains sums of $x^k \cdot y$. This system is then solved using Gaussian Elimination to get all coefficients.

## Model

$$y = a_0 + a_1x + a_2x^2 + \ldots + a_mx^m$$

## Normal Equations

For degree m polynomial with n data points:

$$\begin{bmatrix} n & \sum x & \sum x^2 & \cdots & \sum x^m \\\ \sum x & \sum x^2 & \sum x^3 & \cdots & \sum x^{m+1} \\\ \sum x^2 & \sum x^3 & \sum x^4 & \cdots & \sum x^{m+2} \\\ \vdots & \vdots & \vdots & \ddots & \vdots \\\ \sum x^m & \sum x^{m+1} & \sum x^{m+2} & \cdots & \sum x^{2m} \end{bmatrix} \begin{bmatrix} a_0 \\\ a_1 \\\ a_2 \\\ \vdots \\\ a_m \end{bmatrix} = \begin{bmatrix} \sum y \\\ \sum xy \\\ \sum x^2y \\\ \vdots \\\ \sum x^m y \end{bmatrix}$$

Solve using Gaussian Elimination.
