def print_board(board):
    for row in board:
        print(row)
    print()


# Goal state
goal = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]


# Calculate Manhattan distance
def heuristic(board):
    distance = 0

    for i in range(3):
        for j in range(3):
            value = board[i][j]

            if value == 9:
                continue

            # Find goal position
            for x in range(3):
                for y in range(3):
                    if goal[x][y] == value:
                        distance += abs(i - x) + abs(j - y)

    return distance


# Generate neighboring states
def get_neighbors(board):

    # Find blank (9)
    for i in range(3):
        for j in range(3):
            if board[i][j] == 9:
                blank_i = i
                blank_j = j

    moves = [
        (-1, 0),   # Up
        (1, 0),    # Down
        (0, -1),   # Left
        (0, 1)     # Right
    ]

    neighbors = []

    for di, dj in moves:
        ni = blank_i + di
        nj = blank_j + dj

        if 0 <= ni < 3 and 0 <= nj < 3:

            new_board = [row[:] for row in board]

            # Swap blank with new position
            new_board[blank_i][blank_j], new_board[ni][nj] = \
                new_board[ni][nj], new_board[blank_i][blank_j]

            neighbors.append(new_board)

    return neighbors


# Hill Climbing
def hill_climbing(start):

    current = start
    step = 0

    while True:

        print("Step:", step)
        print_board(current)
        print("Heuristic:", heuristic(current))

        if current == goal:
            print("Goal Reached!")
            return

        neighbors = get_neighbors(current)

        # Find best neighbor
        best = min(neighbors, key=heuristic)

        print("Best neighbor heuristic:", heuristic(best))
        print("-------------------------")

        # If no improvement, stop
        if heuristic(best) >= heuristic(current):
            print("No better neighbor found.")
            print("Hill Climbing stopped.")
            return

        current = best
        step += 1


# Initial state
start = [
    [5, 9, 1],
    [7, 2, 3],
    [8, 6, 4]
]

hill_climbing(start)