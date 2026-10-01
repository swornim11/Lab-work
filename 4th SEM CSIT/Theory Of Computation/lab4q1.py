def turing_machine(input_string):
    # # = blank symbol

    # Add a blank at the end of the input
    tape = list(input_string) + ['#']

    # Initial state
    state = 'q1'

    # Head starts at the first symbol
    head = 0

    while True:

        # STATE q1
        if state == 'q1':

            # q1 : 0 / #, R -> q2
            if tape[head] == '0':
                tape[head] = '#'
                head += 1
                state = 'q2'

            # q1 : 1 / #, R -> q2
            elif tape[head] == '1':
                tape[head] = '#'
                head += 1
                state = 'q2'

            else:
                return False

        # STATE q2
        elif state == 'q2':

            # q2 : 0 / #, R -> q2
            if tape[head] == '0':
                tape[head] = '#'
                head += 1

            # q2 : 1 / #, R -> q2
            elif tape[head] == '1':
                tape[head] = '#'
                head += 1

            # q2 : # / #, N -> q3
            elif tape[head] == '#':
                tape[head] = '#'
                state = 'q3'

            else:
                return False

        # STATE q3
        elif state == 'q3':
            return tape


# MAIN PROGRAM
print("Turing Machine: Erase All Symbols")
print("Blank symbol: #")

while True:

    input_string = input(
        "\nEnter a string over {0,1} (or 'exit' to stop): "
    )

    # Exit condition
    if input_string.lower() == 'exit':
        break

    # Check input
    if any(symbol not in '01' for symbol in input_string):
        print("Invalid input! Enter only 0 and 1.")
        continue

    # Run the TM
    final_tape = turing_machine(input_string)

    print("Initial tape :", input_string + "#")
    print("Final tape   :", ''.join(final_tape))