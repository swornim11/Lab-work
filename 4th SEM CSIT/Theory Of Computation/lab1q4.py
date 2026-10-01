#must have 01 and 10 as substring
transitions = {
    ('q0', '0'): 'q1',
    ('q0', '1'): 'q2',

    ('q1', '0'): 'q1',
    ('q1', '1'): 'q3',

    ('q2', '0'): 'q4',
    ('q2', '1'): 'q2',

    ('q3', '0'): 'q5',
    ('q3', '1'): 'q3',

    ('q4', '0'): 'q4',
    ('q4', '1'): 'q5',

    ('q5', '0'): 'q5',
    ('q5', '1'): 'q5',
}

start_state = 'q0'       # where the DFA begins
accept_states = ['q5']   # both 01 and 10 have been found

# Take the binary string from the user
input_string = input("Enter a binary string (0s and 1s only): ")

# Begin at the start state
current_state = start_state

print("Start state:", current_state)

# Read the string one character at a time
for symbol in input_string:
    current_state = transitions[(current_state, symbol)]
    print("Read", symbol, "-> moved to state", current_state)

print("Final state:", current_state)

# Decide accept or reject
if current_state in accept_states:
    print("Result: ACCEPTED")
else:
    print("Result: REJECTED")