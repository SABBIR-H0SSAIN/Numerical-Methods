# 🔢 Runge-Kutta 4th Order Method (RK4)

A powerful numerical method for solving ordinary differential equations with high accuracy.

---

## 📖 Theory

The **Runge-Kutta 4th Order (RK4)** method solves first-order ODEs of the form:

$$\frac{dy}{dx} = f(x, y) \quad \text{with} \quad y(x_0) = y_0$$

### How It Works

The method estimates the slope at **four strategic points** within each step:

| Slope | Location | Description |
|:-----:|:---------|:------------|
| $k_1$ | Beginning | Slope at $(x_n, y_n)$ |
| $k_2$ | Midpoint | Slope using $k_1$ to estimate $y$ |
| $k_3$ | Midpoint | Slope using $k_2$ to estimate $y$ |
| $k_4$ | End | Slope using $k_3$ to estimate $y$ |

These four slopes are combined using a **weighted average** (weights: 1, 2, 2, 1) to achieve 4th-order accuracy.

---

## 📐 Formula

### Step 1: Compute the Four Slopes

$$\boxed{k_1 = h \cdot f(x_n, y_n)}$$

$$\boxed{k_2 = h \cdot f\left(x_n + \frac{h}{2}, \ y_n + \frac{k_1}{2}\right)}$$

$$\boxed{k_3 = h \cdot f\left(x_n + \frac{h}{2}, \ y_n + \frac{k_2}{2}\right)}$$

$$\boxed{k_4 = h \cdot f(x_n + h, \ y_n + k_3)}$$

### Step 2: Update Values

$$\boxed{y_{n+1} = y_n + \frac{1}{6}\left(k_1 + 2k_2 + 2k_3 + k_4\right)}$$

$$\boxed{x_{n+1} = x_n + h}$$

---

## 📊 Accuracy

| Error Type | Order |
|:-----------|:-----:|
| Local Truncation Error | $O(h^5)$ |
| Global Error | $O(h^4)$ |

> 💡 **Note:** Smaller step size $h$ leads to higher accuracy but requires more computation.
