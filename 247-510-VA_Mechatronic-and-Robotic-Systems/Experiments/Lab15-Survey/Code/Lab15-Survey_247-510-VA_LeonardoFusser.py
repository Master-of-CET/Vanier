import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import Perceptron, LinearRegression
from sklearn.metrics import accuracy_score


#region Load dataset, shuffle it and split it according to the 80/20 rule.
# Load the CSV data from the text file.
data = np.loadtxt('Mechatronics Survey - CLEAN.csv', delimiter=',', skiprows=1)
#print(data)

# We must reshape the 1D array into a 2D array.
S = data[:, 5].reshape(-1, 1)
#print(S)
D = data[:, 7].reshape(-1, 1)
#print(D)
J = data[:, 9].reshape(-1, 1)
#print(J)

X = data[:, :5]

#Y = data[:, 4].reshape(-1, 1) # We need an array of 1D arrays for the Scikit library.
#print(Y)
# Note: The output vector is either 0 or 1!

test_ratio = 0.2             # 20% of the data should be used for testing.
X_S_train, X_S_test, Y_S_train, Y_S_test = train_test_split(X, S, test_size=test_ratio)
X_D_train, X_D_test, Y_D_train, Y_D_test = train_test_split(X, D, test_size=test_ratio)
X_J_train, X_J_test, Y_J_train, Y_J_test = train_test_split(X, J, test_size=test_ratio)

def Build_Model(X_train, X_test, Y_train, Y_test):
    Serge = Perceptron()
    Serge.fit(X_train, Y_train)
    Y_predicted = Serge.predict(X_test)
    MSE = np.sum((Y_predicted - Y_test)**2)
    print(MSE)

Build_Model(X_S_train, X_S_test, Y_S_train, Y_S_test)
Build_Model(X_D_train, X_D_test, Y_D_train, Y_D_test)
Build_Model(X_J_train, X_J_test, Y_J_train, Y_J_test)


#endregion


# #region Fit a hyperplane to the data and extract the parameters.
# model = LinearRegression()
# _=model.fit(X_train, Y_train)
# #print(model.coef_)
# #print(model.intercept_)
# #endregion
#
# #region We will use the parameters to manually build the classifier.
# Y_pred_continuous = model.predict(X_test)  # Continuous values. We MUST threshold them.
#
# Ypred = []
# for val in Y_pred_continuous:
#     if val >= 0.5:
#         Ypred.append(1)
#     else:
#         Ypred.append(0)
#
# Ypred = np.array(Ypred)
# #print(Ypred)
# #endregion
#
# #region Test the accuracy of the classifier.
# accuracy = accuracy_score(Ypred, Y_test)*100
# print('The accuracy of our linear classifier is: %.1f' %accuracy)
# #endregion

