def dfs(graph, node, goal, visited=None, path=None):

    if visited is None:
        visited = set()

    if path is None:
        path = []

    visited.add(node)
    path.append(node)

    print("Current node:", node)
    print("Path:", path)

    # Goal found
    if node == goal:
        print("Goal reached!")
        return path

    # Visit neighbors
    for neighbor in graph[node]:

        if neighbor not in visited:

            result = dfs(
                graph,
                neighbor,
                goal,
                visited,
                path
            )

            if result:
                return result

    # Backtrack
    path.pop()
    print("Backtracking from:", node)

    return None


# Graph
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': [],
    'F': []
}

# DFS
result = dfs(graph, 'A', 'F')

print("\nDFS Path:", result)