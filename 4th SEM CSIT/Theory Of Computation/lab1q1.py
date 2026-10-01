# dfs that ends with 0 and 1
transitions = {
    ('q0', '0'): 'q1',
    ('q0', '1'): 'q1',
    ('q1', '0'): 'q1',
    ('q1', '1'): 'q1',
}

start_state = 'q0'       # where the DFA begins
accept_states = ['q1']   # the DFA accepts if it ends in q1

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