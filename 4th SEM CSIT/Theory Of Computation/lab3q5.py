def pda_accepts(string):

    # Try every possible position as the middle
    # of W and W^R
    for middle in range(1, len(string)):
        

        # Initial state
        state = 'q0'

        # Initial stack
        stack = ['Z0']

        print("\n--------------------------------")
        print("Trying middle position:", middle)
        print("--------------------------------")

        # q0: Read W and push symbols
        valid = True

        for i in range(middle):
            symbol = string[i]

            if symbol == 'a' or symbol == 'b':

                # Push input symbol
                stack.append(symbol)

                print(
                    f"Read: {symbol} | "
                    f"Action: PUSH {symbol} | "
                    f"State: q0 | "
                    f"Stack: {stack}"
                )

            else:
                valid = False
                break

        if not valid:
            continue

        # ε-transition
        # q0 -> q1
        # No stack operation

        state = 'q1'

        print(
            "ε-transition | "
            "Action: NO STACK CHANGE | "
            "State: q0 -> q1 | "
            f"Stack: {stack}"
        )

        # q1: Read W^R and pop
        for i in range(middle, len(string)):

            symbol = string[i]

            if symbol == 'a' and stack[-1] == 'a':

                stack.pop()

                print(
                    f"Read: {symbol} | "
                    "Action: POP a | "
                    "State: q1 | "
                    f"Stack: {stack}"
                )

            elif symbol == 'b' and stack[-1] == 'b':

                stack.pop()

                print(
                    f"Read: {symbol} | "
                    "Action: POP b | "
                    "State: q1 | "
                    f"Stack: {stack}"
                )

            else:
                valid = False
                break

        # Acceptance condition
        if valid and stack == ['Z0']:

            print(
                "ε-transition | "
                "Z0 remains | "
                "q1 -> qf"
            )

            return True

    return False


# Main Program

print("PDA for L = { WW^R | W ∈ {a,b}* }")

string = input("Enter a string: ")

if pda_accepts(string):
    print("\nResult: ACCEPTED")
else:
    print("\nResult: REJECTED")