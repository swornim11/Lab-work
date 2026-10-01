def neuron(x1, x2):

    # Weights and bias
    w1 = 1
    w2 = 1
    bias = -0.5

    # Weighted sum
    net = (x1 * w1) + (x2 * w2) + bias

    # Step activation function
    if net >= 0:
        output = 1
    else:
        output = 0

    print("Input:", x1, x2)
    print("Net =", net)
    print("Output =", output)
    print("--------------------")

    return output


# OR gate inputs
neuron(0, 0)
neuron(0, 1)
neuron(1, 0)
neuron(1, 1)