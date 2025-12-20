# Linear Regression

## Theory

Linear Regression is a method to find the best-fitting straight line through a set of data points. Given n points, we want to find a line $y = a + bx$ such that the sum of squared vertical distances from each point to the line is minimized. This is called the Least Squares Method.

The slope $b$ represents how much $y$ changes for a unit change in $x$. The intercept $a$ is the value of $y$ when $x = 0$.

## Model

$$y = a + bx$$

## Formulas

$$b = \frac{n \sum xy - \sum x \sum y}{n \sum x^2 - (\sum x)^2}$$

$$a = \frac{\sum y - b \sum x}{n}$$
