def goal_based_agent(current, goal):
    if current == goal:
        return "Goal reached!"
    
    if current < goal:
        return "Move forward"
    else:
        return "Move backward"


# Example
current_position = 1
goal_position = 4

while current_position != goal_position:
    action = goal_based_agent(current_position, goal_position)
    print("Position:", current_position, "->", action)

    if current_position < goal_position:
        current_position += 1
    else:
        current_position -= 1

print("Position:", current_position, "-> Goal reached!")