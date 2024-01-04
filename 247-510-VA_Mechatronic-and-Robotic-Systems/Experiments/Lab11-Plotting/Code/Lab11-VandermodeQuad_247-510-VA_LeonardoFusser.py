import numpy as np
import matplotlib.pyplot as plt

#region Create dataset
N = 100
x_data = np.linspace(-1, 10, N)

# We will set parameters for our model and try to recover them.
a0 = 2
a1 = 3

# Add noise to corrupt the values (measurement error).
err = 0
epsilon = err*np.random.randn(N)
y = a1*x_data + a0
y_data = y + epsilon

#plt.plot(x_data, (a1*x_data + a0) + epsilon, '.')
#plt.hist(epsilon, bins=20)
#plt.show()
#endregion

#region Find optimal coefficients for the polynomial.
X = np.array([
    [N, np.sum(x_data), np.sum(x_data**2)],
    [np.sum(x_data), np.sum(x_data**2), np.sum(x_data**3)],
    [np.sum(x_data), np.sum(x_data**3), np.sum(x_data**4)]
    ])

Y = np.array([
    [np.sum(1*y_data)],
    [np.sum(x_data*y_data)],
    [np.sum(x_data**2 * y_data)]
    ])

X_inv = np.linalg.pinv(X)
a = np.dot(X_inv, Y)
#endregion

#region Build model and calculate MSE.
y_model = a[2]*x_data**2 + a[1]*x_data + a[0]
MSE = np.sum((y_data - y_model)**2)
#endregion

#region Plot the output.
plt.plot(x_data, y_data, 'g.')
plt.plot(x_data, y_model, 'r--')
plt.title('MSE = %4.2f' %MSE)
plt.show()
#endregion
