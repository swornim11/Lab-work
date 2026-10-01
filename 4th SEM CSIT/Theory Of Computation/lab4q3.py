def turing_machine(input_string):
    # # is the blank symbol
    tape = list(input_string) + ['#']

    # Initial state
    state = 'q0'

    # Head starts at the first symbol
    head = 0

    while True:

        # STATE q0
        if state == 'q0':

            # q0: 0 / 1, R -> q0
            if tape[head] == '0':
                tape[head] = '1'
                head += 1

            # q0: 1 / 0, R -> q0
            elif tape[head] == '1':
                tape[head] = '0'
                head += 1

            # q0: # / #, N -> q1
            elif tape[head] == '#':
                state = 'q1'

            else:
                return False

        # STATE q1
        elif state == 'q1':
            return True


# MAIN PROGRAM
print("---Swornim Maharjan---")
print("Turing Machine: Binary Complement")
print("0 -> 1")
print("1 -> 0")

while True:

    input_string = input(
        "\nEnter a binary string (or 'exit' to stop): "
    )

    # Exit condition
    if input_string.lower() == 'exit':
        break

    # Validate input
    if any(symbol not in '01' for symbol in input_string):
        print("Invalid input! Enter only 0 and 1.")
        continue

    # Run the Turing Machine
    accepted = turing_machine(input_string)

    # Create the output tape
    tape = list(input_string) + ['#']
    head = 0

    while tape[head] != '#':

        if tape[head] == '0':
            tape[head] = '1'

        elif tape[head] == '1':
            tape[head] = '0'

        head += 1

    # Remove blank symbol
    output = ''.join(tape[:-1])

    print("Input  :", input_string)
    print("Output :", output)

    if accepted:
        print("Accepted")
    else:
        print("Rejected")