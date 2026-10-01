def turing_machine(input_string):
    # Blank symbol
    BLANK = '#'

    # Create tape
    tape = list(input_string) + [BLANK]

    # Initial state
    state = 'q0'

    # Head starts at first symbol
    head = 0

    while True:

        # STATE q0
        if state == 'q0':

            # q0 -- a/#,R --> q1
            if tape[head] == 'a':
                tape[head] = '#'
                head += 1
                state = 'q1'

            # q0 -- #/#,N --> h
            elif tape[head] == '#':
                state = 'h'

            # No transition for b
            else:
                return False

        # STATE q1
        elif state == 'q1':

            # q1 -- a/a,R --> q1
            if tape[head] == 'a':
                tape[head] = 'a'
                head += 1

            # q1 -- b/b,R --> q1
            elif tape[head] == 'b':
                tape[head] = 'b'
                head += 1

            # q1 -- #/#,L --> q2
            elif tape[head] == '#':
                head -= 1
                state = 'q2'

            else:
                return False

        # STATE q2
        elif state == 'q2':

            # q2 -- b/#,L --> q3
            if tape[head] == 'b':
                tape[head] = '#'
                head -= 1
                state = 'q3'

            else:
                return False

        # STATE q3
        elif state == 'q3':

            # q3 -- a/a,L --> q3
            if tape[head] == 'a':
                tape[head] = 'a'
                head -= 1

            # q3 -- b/b,L --> q3
            elif tape[head] == 'b':
                tape[head] = 'b'
                head -= 1

            # q3 -- #/#,R --> q0
            elif tape[head] == '#':
                head += 1
                state = 'q0'

            else:
                return False

        # ACCEPTING STATE
        elif state == 'h':
            return True


# MAIN PROGRAM
print("---Swornim Maharjan---")
print("Turing Machine for L = { a^n b^n | n >= 1 }")

while True:

    string = input(
        "\nEnter a string over {a,b} (or 'exit'): "
    )

    # Exit condition
    if string.lower() == 'exit':
        break

    # Check input
    if any(symbol not in 'ab' for symbol in string):
        print("Invalid input! Use only a and b.")
        continue

    # Run Turing Machine
    if turing_machine(string):
        print("Accepted")
    else:
        print("Rejected")