import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score
from sklearn import datasets
import numpy as np

# region Load data from the MNIST dataset for handwritten digits.
# Load target output labels and load input images (convert 8x8
# images to a single 1x64 vector).
digits = datasets.load_digits()
y = digits.target
x = digits.images.reshape((len(digits.images), -1))
N = len(digits.images)
# endregion
# region Split the data into training and test data (80/20 rule).
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
# endregion
# region Declare and train a multilayer Perceptron as a classifier with 15 neurons in a hidden layer.
mlp = MLPClassifier(hidden_layer_sizes=(15, ), activation='logistic', alpha=1e-4,
                    solver='sgd', tol=1e-4, random_state=1,
                    learning_rate_init=.1, max_iter=500, verbose=True)
mlp.fit(x_train, y_train)
predictions = mlp.predict(x_test)
score = accuracy_score(y_test, predictions)
# endregion
# region Plot the loss curve for the network during training.
plt.figure(1)
plt.semilogy(mlp.loss_curve_)
plt.title('Training Error Reduction\n(%.2f%% Accuracy)'%(score*100), fontweight='bold')
plt.xlabel('Training Epochs')
plt.ylabel('Training Error')
# endregion
# region Select 16 random images and plot their predictions (images are 8x8).
plt.figure(2, figsize=(6.5, 8))
random_idx = np.random.randint(0, N-1, 16)    # The index of 16 randomly sampled indices into the input data.
for s in range(16):
    plt.subplot(4, 4, s+1)
    idx = random_idx[s]
    digit_image = x[idx].reshape((8, 8))
    predicted_digit = mlp.predict(x[idx].reshape(1, -1))
    plt.imshow(digit_image, cmap='gray_r')
    plt.axis('off')
    plt.title('Predicted\nDigit: %d'%predicted_digit)
plt.suptitle('16 Randomly Selected\nDigits with Predictions', fontsize=18, fontweight='bold')
plt.show()
#endregion
