def turing_machine(input_string):
    # # = blank symbol

    tape = list(input_string) + ['#']

    # q1 = even number of symbols read
    # q2 = odd number of symbols read
    # q1 = accepting state

    state = 'q1'
    head = 0

    while True:

        # STATE q1
        if state == 'q1':

            # q1 -- a/a,R --> q2
            if tape[head] == 'a':
                tape[head] = 'a'
                head += 1
                state = 'q2'

            # q1 -- b/b,R --> q2
            elif tape[head] == 'b':
                tape[head] = 'b'
                head += 1
                state = 'q2'

            # q1 -- #/#,N --> ACCEPT
            elif tape[head] == '#':
                return True

        # STATE q2
        elif state == 'q2':

            # q2 -- a/a,R --> q1
            if tape[head] == 'a':
                tape[head] = 'a'
                head += 1
                state = 'q1'

            # q2 -- b/b,R --> q1
            elif tape[head] == 'b':
                tape[head] = 'b'
                head += 1
                state = 'q1'

            # q2 -- #/#,N --> REJECT
            elif tape[head] == '#':
                return False


# MAIN PROGRAM
print("--Swornim Maharjan---")
print("Turing Machine for Even Length Strings")
print("Language: L = { w ∈ {a,b}* | |w| is even }")

while True:

    input_string = input(
        "\nEnter a string over {a,b} (or 'exit' to stop): "
    )

    # Exit condition
    if input_string.lower() == 'exit':
        break

    # Check input
    if any(symbol not in 'ab' for symbol in input_string):
        print("Invalid input! Use only a and b.")
        continue

    # Run TM
    if turing_machine(input_string):
        print("Accepted")
    else:
        print("Rejected")