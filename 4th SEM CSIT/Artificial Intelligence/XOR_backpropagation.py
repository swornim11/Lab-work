import numpy as np

# XOR input
X = np.array([
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
])

# XOR target
Y = np.array([
    [0],
    [1],
    [1],
    [0]
])


# Sigmoid activation function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))


# Derivative of sigmoid
def sigmoid_derivative(x):
    return x * (1 - x)


# Set random seed
np.random.seed(1)

# Initialize weights
W1 = np.random.uniform(-1, 1, (2, 2))
W2 = np.random.uniform(-1, 1, (2, 1))

# Biases
b1 = np.zeros((1, 2))
b2 = np.zeros((1, 1))

# Learning rate
learning_rate = 0.5

# Training
for epoch in range(10000):

    # ---------------- FORWARD PROPAGATION ----------------

    hidden_input = np.dot(X, W1) + b1
    hidden_output = sigmoid(hidden_input)

    output_input = np.dot(hidden_output, W2) + b2
    output = sigmoid(output_input)


    # ---------------- BACKPROPAGATION ----------------

    error = Y - output

    output_delta = error * sigmoid_derivative(output)

    hidden_error = np.dot(output_delta, W2.T)

    hidden_delta = hidden_error * sigmoid_derivative(hidden_output)


    # ---------------- UPDATE WEIGHTS ----------------

    W2 += np.dot(hidden_output.T, output_delta) * learning_rate
    b2 += np.sum(output_delta, axis=0, keepdims=True) * learning_rate

    W1 += np.dot(X.T, hidden_delta) * learning_rate
    b1 += np.sum(hidden_delta, axis=0, keepdims=True) * learning_rate


    # Show process
    if epoch % 1000 == 0:
        loss = np.mean(error ** 2)
        print("Epoch:", epoch, "Error:", loss)


# ---------------- TESTING ----------------

print("\nXOR Results:")

for i in range(len(X)):
    print(
        X[i],
        "=>",
        round(output[i][0], 3)
    )