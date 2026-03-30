# To solve the Water Jug Problem using Depth First Search (DFS) by exploring all possible states to measure a target quantity of water using two jugs of fixed capacities.

import matplotlib.pyplot as plt
import networkx as nx
# Initial setup
capacity1 = 3  # Capacity of the 3-liter jug
capacity2 = 5  # Capacity of the 5-liter jug
target = 4     # Target amount to measure
jug1 = 0  # Start with 0 liters in the 3-liter jug
jug2 = 0  # Start with 0 liters in the 5-liter jug
# To track visited states and the path
visited = set()  # Set to keep track of visited states
path = []  # List to record the steps we take



# Main loop to simulate the steps
def dfs(jug1, jug2):
    # If we have already visited this state, we stop to avoid cycles
    if (jug1, jug2) in visited:
        return False
    # Add the current state to visited and path
    visited.add((jug1, jug2))
    path.append((jug1, jug2))
    # Check if we've reached the target
    if jug1 == target or jug2 == target:
        return True
    # Try all possible actions (we test each one step by step)
    # 1. Fill the 3-liter jug
    if jug1 != capacity1:
        if dfs(capacity1, jug2):
            return True

    # 2. Fill the 5-liter jug
    if jug2 != capacity2:
        if dfs(jug1, capacity2):
            return True

    # 3. Empty the 3-liter jug
    if jug1 != 0:
        if dfs(0, jug2):
            return True

    # 4. Empty the 5-liter jug
    if jug2 != 0:
        if dfs(jug1, 0):
            return True

    # 5. Pour water from 3-liter jug into 5-liter jug
    if jug1 > 0 and jug2 < capacity2:
        transfer = min(jug1, capacity2 - jug2)
        if dfs(jug1 - transfer, jug2 + transfer):
            return True

    # 6. Pour water from 5-liter jug into 3-liter jug
    if jug2 > 0 and jug1 < capacity1:
        transfer = min(jug2, capacity1 - jug1)
        if dfs(jug1 + transfer, jug2 - transfer):
            return True

    # If no solution found, backtrack
    path.pop()
    return False

# Start DFS with both jugs empty
solution_found = dfs(jug1, jug2)

# If a solution is found, print the solution steps
if solution_found:
    print("Solution found!")
    for step in path:
        print(step)
else:
    print("No solution found.")


# Function to create and visualize the state space transitions for DFS
def visualize_dfs_solution(path):
    G = nx.DiGraph()

    # Add the nodes and edges based on the DFS solution path
    for i in range(len(path) - 1):
        G.add_edge(path[i], path[i + 1])


    pos = nx.spring_layout(G)  # Position the nodes for visualization

    plt.figure(figsize=(8, 6))

    # Draw the graph with nodes and labels
    nx.draw(G, pos, with_labels=True, node_color='lightgreen', node_size=1500, font_size=12, font_weight='bold')
    nx.draw_networkx_edges(G, pos, edgelist=list(G.edges()), edge_color='blue', width=2)


    plt.title("Water Jug Problem - DFS Solution Path")
    plt.show()



# Visualize the DFS solution
if solution_found:
    visualize_dfs_solution(path)


