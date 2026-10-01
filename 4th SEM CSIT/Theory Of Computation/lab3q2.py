def pda_accepts(string):

    # Initial state
    state = 'q0'

    # Initial stack
    stack = ['Z0']

    print("\nInitial State:", state)
    print("Initial Stack:", stack)

    i = 0

    while i < len(string):
        symbol = string[i]

        # State q0: Read a's and push A
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

                # Start reading b's and pop A
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

        # State q1: Match b's with A's
        elif state == 'q1':

            if symbol == 'b' and stack[-1] == 'A':

                # Pop A for each b
                stack.pop()

                print(
                    f"Read: {symbol} | "
                    f"Action: POP A | "
                    f"State: q1 | "
                    f"Stack: {stack}"
                )

                i += 1

            elif symbol == 'b' and stack[-1] == 'Z0':

                # This is the extra b
                state = 'q2'

                print(
                    f"Read: {symbol} | "
                    f"Action: EXTRA b | "
                    f"State: q2 | "
                    f"Stack: {stack}"
                )

                i += 1

            else:
                return False

        # State q2: Extra b has been read
        elif state == 'q2':

            # No more input should remain
            return False

    # Accept only if:
    # 1. We reached q2
    # 2. Stack contains only Z0
    # 3. All input has been consumed

    if state == 'q2' and stack == ['Z0']:
        return True

    return False


# Main Program

print("PDA for L = { a^n b^(n+1) | n >= 1 }")

string = input("Enter a string containing a's and b's: ")

if pda_accepts(string):
    print("\nResult: ACCEPTED")
else:
    print("\nResult: REJECTED")