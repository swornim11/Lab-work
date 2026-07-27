transitions = {
    ('q0', '0'): ['q0', 'q1'],  # stay in q0, AND guess this 0 starts "01"
    ('q0', '1'): ['q0'],        # just keep waiting
    ('q1', '1'): ['q2'],        # the guessed 0 is followed by 1 -> accept
    # q2 has no outgoing transitions
}

start_state = 'q0'
accept_states = ['q2']

print("---Swornim Maharjan---")
print("---NFA ends with '01'---")

# Take the binary string from the user
input_string = input("Enter a binary string (0s and 1s only): ")

# An NFA can be in several states at once, so we track a SET of active states
current_states = {start_state}

print("Start states:", current_states)

# Read the string one character at a time
for symbol in input_string:
    next_states = set()

    for state in current_states:
        if (state, symbol) in transitions:
            next_states.update(transitions[(state, symbol)])

    current_states = next_states
    print("Read", symbol, "-> active states:", current_states)

print("Final states:", current_states)

# The NFA accepts if AT LEAST ONE active state is an accept state
if current_states & set(accept_states):
    print("Result: ACCEPTED")
else:
    print("Result: REJECTED")