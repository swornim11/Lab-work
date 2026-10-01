def simple_reflex_agent(room, status):
    if status == "dirty":
        return "Clean the room"
    else:
        return "Move to another room"


# Example
room = "Room A"
status = "dirty"

action = simple_reflex_agent(room, status)

print("Room:", room)
print("Status:", status)
print("Action:", action)