def search(start, goal, neighbors_fn, use_bfs=True):
    # Choose BFS or DFS
    frontier = QueueFrontier() if use_bfs else StackFrontier()

    # Add the start node
    start_node = Node(state=start, parent=None, action=None)
    frontier.add(start_node)

    explored = set()

    while not frontier.empty():
        # Take node from frontier
        node = frontier.remove()

        # Check if goal found
        if node.state == goal:
            # Reconstruct path
            actions = []
            cells = []
            while node.parent is not None:
                actions.append(node.action)
                cells.append(node.state)
                node = node.parent
            actions.reverse()
            cells.reverse()
            return actions, cells  # solution path

        explored.add(node.state)

        # Expand neighbors
        for action, state in neighbors_fn(node.state):
            if not frontier.contains_state(state) and state not in explored:
                child = Node(state=state, parent=node, action=action)
                frontier.add(child)

    return None  # no solution




def neighbors(state):
    x, y = state
    moves = [
        ("up", (x, y - 1)),
        ("down", (x, y + 1)),
        ("left", (x - 1, y)),
        ("right", (x + 1, y)),
    ]
    # Filter out invalid positions
    return [(action, pos) for action, pos in moves if 0 <= pos[0] < 3 and 0 <= pos[1] < 3]

start = (0, 0)
goal = (2, 2)

# BFS
print("BFS:", search(start, goal, neighbors, use_bfs=True))

# DFS
print("DFS:", search(start, goal, neighbors, use_bfs=False))
