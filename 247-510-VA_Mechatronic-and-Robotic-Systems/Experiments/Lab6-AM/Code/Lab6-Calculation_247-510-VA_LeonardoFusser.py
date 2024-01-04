import numpy as np

#region Calculate values of a parabola.
t = np.linspace(0, 2*np.pi, 100)
f = np.sin(t)
print(f)
#endregion

#region Calculate the sum of numbers between 1 and 100.

#endregion

#region Calculate the sum of numbers between 1 and 25.
N = np.linspace(1, 25, 25)
N2 = N**2
Sum_N2 = np.sum(N2)
print(Sum_N2)
#endregion

#region Calculate the sum of polynomial terms.
x = np.array([3, 7, 4, 9, 2, 1, 8, -1, 0, 0])
p = (x**2 - 4)**2
Sum_p = np.sum(p)
#endregion

#region Compute vector dot product.
v1 = np.array([3, 7, 2])
v2 = np.array([7, -1, 3])
vec_dot = np.dot(v1, v2)
print(vec_dot)
#endregion

#region Compute matrix product.
mat = np.array([[3, 7, 2],
                 [6, 1, 7],
                 [-4, 3, 0]])
vec = np.array([2, 9, 3])
mat_vec_mult = np.dot(mat, vec)
print(mat_vec_mult)
#endregion
