import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression as lr

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

#endregion
a = lr.fit(x_data, y_data)
y_model = 
MSE = lr.score(a)

#region Plot the output.
plt.plot(x_data, y_data, 'g.')
plt.plot(x_data, y_model(x_data), 'r--')
plt.title('MSE = %4.2f' %MSE)
plt.show()
#endregion
