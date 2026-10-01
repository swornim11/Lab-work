# PDA for L = { a^n b^m c^n | n,m >= 1 }


def pda_accepts(string):
    print("---lab3q3---")
    print("swornim maharjan")

    # Initial state
    state = 'q0'

    # Initial stack
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


            elif symbol == 'b' and stack[-1] == 'A':

                # First b: change state only
                state = 'q1'

                print(
                    f"Read: {symbol} | "
                    f"Action: NO STACK CHANGE | "
                    f"State: q0 -> q1 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False


        # q1: Read b's
        elif state == 'q1':

            if symbol == 'b' and stack[-1] == 'A':

                # Continue reading b's
                print(
                    f"Read: {symbol} | "
                    f"Action: NO STACK CHANGE | "
                    f"State: q1 | "
                    f"Stack: {stack}"
                )

                i += 1


            elif symbol == 'c' and stack[-1] == 'A':

                # First c: pop A and move to q2
                stack.pop()
                state = 'q2'

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q1 -> q2 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False


        # q2: Read c's and pop A
        elif state == 'q2':

            if symbol == 'c' and stack[-1] == 'A':

                # Pop A for every c
                stack.pop()

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q2 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False


    # Acceptance condition
    # Input consumed
    # Stack contains only Z0
    # Reached q2

    if state == 'q2' and stack == ['Z0']:
        return True

    return False



# Main Program

print("PDA for L = { a^n b^m c^n | n,m >= 1 }")

string = input("Enter a string: ")

if pda_accepts(string):
    print("\nResult: ACCEPTED")
else:
    print("\nResult: REJECTED")