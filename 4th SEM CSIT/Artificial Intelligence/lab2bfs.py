from collections import deque

def bfs(graph, start, goal):

    queue = deque([start])
    visited = set()

    while queue:

        # Remove the first node
        node = queue.popleft()

        print("Removed from queue:", node)

        # Check goal
        if node == goal:
            print("Goal reached!")
            return

        # Visit node
        if node not in visited:
            visited.add(node)

            # Add neighbors to queue
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

        print("Queue:", list(queue))
        print("Visited:", list(visited))
        print("------------------")


# Graph
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# Start BFS
bfs(graph, 'A', 'F')