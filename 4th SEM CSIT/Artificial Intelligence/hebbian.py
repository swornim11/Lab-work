# AND Gate using Hebbian Learning

# Initial weights
w1 = 0
w2 = 0

# AND gate training data
data = [
    (0, 0, 0),
    (0, 1, 0),
    (1, 0, 0),
    (1, 1, 1)
]

# Training
for x1, x2, y in data:

    # Hebbian learning rule
    w1 = w1 + (x1 * y)
    w2 = w2 + (x2 * y)

    print("Input:", x1, x2)
    print("Target:", y)
    print("w1 =", w1)
    print("w2 =", w2)
    print("------------------")


# Testing
print("\nTesting AND Gate:")

for x1, x2, y in data:

    net = (x1 * w1) + (x2 * w2)

    # Step activation
    if net >= 2:
        output = 1
    else:
        output = 0

    print(x1, "AND", x2, "=", output)