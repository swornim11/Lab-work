def pda_accepts(string):
    print("---lab3q1---")
    print("swornim maharjan")
    # Initial state
    state = 'q0'

    # Stack initially contains bottom symbol
    stack = ['Z0']

    print("\nInitial State:", state)
    print("Initial Stack:", stack)

    i = 0

    while i < len(string):
        symbol = string[i]

        # q0: Read a's and push A
        if state == 'q0':
            if symbol == 'a':
                # Push A onto stack
                stack.append('A')

                print(
                    f"Read: {symbol} | "
                    f"Action: PUSH A | "
                    f"State: q0 | "
                    f"Stack: {stack}"
                )

                i += 1

            # First b: change to q1 and pop A
            elif symbol == 'b' and stack[-1] == 'A':
                stack.pop()
                state = 'q1'

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q1 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False

        # q1: Read b's and pop A
        elif state == 'q1':
            if symbol == 'b' and stack[-1] == 'A':
                stack.pop()

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q1 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False

    # Acceptance condition
    # Input must be completely consumed
    # Stack must contain only Z0
    # We must have entered q1
    if state == 'q1' and stack == ['Z0']:
        return True

    return False


# Main Program
print("PDA for L = { a^n b^n | n >= 1 }")

string = input("Enter a string: ")

if pda_accepts(string):
    print("\nResult: ACCEPTED")
else:
    print("\nResult: REJECTED")