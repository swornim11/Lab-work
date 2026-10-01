# PDA for L = { a^n b^m c^m d^n | n,m >= 1 }


def pda_accepts(string):
    print("---lab3q4---")
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

                # Push A
                stack.append('A')

                print(
                    f"Read: {symbol} | "
                    f"Action: PUSH A | "
                    f"State: q0 | "
                    f"Stack: {stack}"
                )

                i += 1


            elif symbol == 'b' and stack[-1] == 'A':

                # First b: change state and push B
                state = 'q1'
                stack.append('B')

                print(
                    f"Read: {symbol} | "
                    f"Action: PUSH B | "
                    f"State: q0 -> q1 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False



        # q1: Read b's and push B
        elif state == 'q1':

            if symbol == 'b':

                # Push B
                stack.append('B')

                print(
                    f"Read: {symbol} | "
                    f"Action: PUSH B | "
                    f"State: q1 | "
                    f"Stack: {stack}"
                )

                i += 1


            elif symbol == 'c' and stack[-1] == 'B':

                # First c: pop B and move to q2
                stack.pop()
                state = 'q2'

                print(
                    f"Read: {symbol} | "
                    f"Action: POP B | "
                    f"State: q1 -> q2 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False



        # q2: Read c's and pop B
        elif state == 'q2':

            if symbol == 'c' and stack[-1] == 'B':

                # Pop B
                stack.pop()

                print(
                    f"Read: {symbol} | "
                    f"Action: POP B | "
                    f"State: q2 | "
                    f"Stack: {stack}"
                )

                i += 1


            elif symbol == 'd' and stack[-1] == 'A':

                # First d: pop A and move to q3
                stack.pop()
                state = 'q3'

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q2 -> q3 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False



        # q3: Read d's and pop A
        elif state == 'q3':

            if symbol == 'd' and stack[-1] == 'A':

                # Pop A
                stack.pop()

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q3 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False



    # Acceptance condition
    # Input completely consumed
    # Stack contains only Z0
    # State must be q3

    if state == 'q3' and stack == ['Z0']:
        return True

    return False



# Main Program

print("PDA for L = { a^n b^m c^m d^n | n,m >= 1 }")

string = input("Enter a string: ")

if pda_accepts(string):
    print("\nResult: ACCEPTED")
else:
    print("\nResult: REJECTED")