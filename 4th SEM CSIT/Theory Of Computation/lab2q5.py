transitions = {
    ('q0', 'a'): ['q0', 'q1'],
    ('q0', 'b'): ['q0', 'q2'],

    ('q1', 'a'): ['q3'],
    ('q2', 'b'): ['q3'],

    ('q3', 'a'): ['q3'],
    ('q3', 'b'): ['q3']
}

start_state = 'q0'
accept_states = ['q3']

print("---Swornim Maharjan---")
print("---NFA that accepts either two consecutive a’s or two  consecutive b’s---")

# Take the input string from the user
input_string = input("Enter a string over {a,b}: ")

# An NFA can be in several states at once
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

# Check acceptance
if current_states & set(accept_states):
    print("Result: ACCEPTED")
else:
    print("Result: REJECTED")