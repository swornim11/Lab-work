import heapq

def a_star(graph, heuristic, start, goal):
    # Priority queue: (f_cost, current_node, path, g_cost)
    queue = [(0, start, [start], 0)]
    visited = set()

    while queue:
        f, current, path, g = heapq.heappop(queue)

        if current in visited:
            continue

        visited.add(current)

        # Goal reached
        if current == goal:
            return path, g

        # Explore neighbors
        for neighbor, cost in graph[current]:
            if neighbor not in visited:
                new_g = g + cost
                new_f = new_g + heuristic[neighbor]

                heapq.heappush(
                    queue,
                    (new_f, neighbor, path + [neighbor], new_g)
                )

    return None, None


# Graph
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('E', 1)],
    'D': [('G', 5)],
    'E': [('G', 2)],
    'G': []
}

# Heuristic values (h(n))
heuristic = {
    'A': 7,
    'B': 6,
    'C': 3,
    'D': 4,
    'E': 2,
    'G': 0
}

# Find path
path, cost = a_star(graph, heuristic, 'A', 'G')

print("Shortest Path:", path)
print("Total Cost:", cost)