import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import accuracy_score

#region Load dataset, shuffle it and split it according to the 80/20 rule.
# Load the CSV data from the text file.
data = np.loadtxt('data_banknote_authentication.txt', delimiter=',')
#print(data)

# Separate the data into the input X and the output Y.
X = data[:, :4]              # The input is in the first 4 columns.
#print(X)
Y = data[:, 4].reshape(-1,1) # We need an array of 1D arrays for the Scikit library.
#print(Y)
# Note: The output vector is either 0 or 1!

test_ratio = 0.2             # 20% of the data should be used for testing.
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=test_ratio)
#endregion

#region Fit a hyperplane to the data and extract the parameters.
model = LinearRegression()
_=model.fit(X_train, Y_train)
#print(model.coef_)
#print(model.intercept_)
#endregion

#region We will use the parameters to manually build the classifier.
Y_pred_continuous = model.predict(X_test)  # Continuous values. We MUST threshold them.

Ypred = []
for val in Y_pred_continuous:
    if val >= 0.5:
        Ypred.append(1)
    else:
        Ypred.append(0)

Ypred = np.array(Ypred)
#print(Ypred)
#endregion

#region Test the accuracy of the classifier.
accuracy = accuracy_score(Ypred, Y_test)*100
print('The accuracy of our linear classifier is: %.1f' %accuracy)
#endregion
