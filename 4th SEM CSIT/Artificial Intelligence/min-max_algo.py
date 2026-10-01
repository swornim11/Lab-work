def minimax(node, maximizing, tree):

    # If node is a leaf node
    if isinstance(tree[node], int):
        print("Leaf", node, "=", tree[node])
        return tree[node]

    if maximizing:
        best = float('-inf')

        print("\nMAX node:", node)

        for child in tree[node]:
            value = minimax(child, False, tree)

            print("MAX compares:", best, "and", value)

            best = max(best, value)

        print("MAX", node, "chooses:", best)
        return best

    else:
        best = float('inf')

        print("\nMIN node:", node)

        for child in tree[node]:
            value = minimax(child, True, tree)

            print("MIN compares:", best, "and", value)

            best = min(best, value)

        print("MIN", node, "chooses:", best)
        return best


# Game tree
tree = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],

    'D': 3,
    'E': 9,
    'F': 2,
    'G': 7
}


# Start Minimax
result = minimax('A', True, tree)

print("\nBest value for MAX:", result)