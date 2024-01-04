import numpy as np
import matplotlib.pyplot as plt

#region Create dataset
N = 100
x_data = np.linspace(-1, 10, N)

# We will set parameters for our model and try to recover them.
a0 = 2
a1 = 3

# Add noise to corrupt the values (measurement error).
err = 10
epsilon = err*np.random.randn(N)
y = a1*x_data + a0
y_data = y + epsilon

#plt.plot(x_data, (a1*x_data + a0) + epsilon, '.')
#plt.hist(epsilon, bins=20)
#plt.show()
#endregion

#region Find optimal coefficients for the polynomial using NumPy.
polyOrder = 15
a = np.polyfit(x_data, y_data, polyOrder)
y_model = np.poly1d(a)
MSE = np.sum((y_data - y_model(x_data))**2)
#endregion

#region Plot the output.
plt.plot(x_data, y_data, 'g.')
plt.plot(x_data, y_model(x_data), 'r--')
plt.title('MSE = %4.2f' %MSE)
plt.show()
#endregion
