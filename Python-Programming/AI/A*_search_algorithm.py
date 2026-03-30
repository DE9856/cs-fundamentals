# To develop a program that applies the A* search algorithm by combining actual path cost and heuristic estimation to efficiently determine the shortest path in a weighted graph.

import networkx as nx
import matplotlib.pyplot as plt


# Define the graph as a dictionary
Graph_nodes = {  #level1
    'A': [('B', 2), ('E', 3)],  #level2
    'B': [('C', 1), ('G', 9)],  #level2
    'C': [],  #level2
    'E': [('D', 6)],  #level2
    'D': [('G', 1)],  #level2
    'G': []  #level2
}  #level1


# Define heuristic function
def heuristic(n):  #level1
    H_dist = {  #level2
        'A': 11,  #level3
        'B': 6,  #level3
        'C': 99,  #level3
        'D': 1,  #level3
        'E': 7,  #level3
        'G': 0,  #level3
    }  #level2
    return H_dist[n]  #level1


# Define function to return neighbors
def get_neighbors(v):  #level1
    return Graph_nodes.get(v, [])  #level2


# Implement A* algorithm
def aStarAlgo(start_node, stop_node):  #level1
    open_set = set([start_node])  #level2
    closed_set = set()  #level2
    g = {start_node: 0}  # Cost from start to node  #level2
    parents = {start_node: start_node}  # Parent tracking  #level2


    while open_set:  #level2
        n = None  #level3
        for v in open_set:  #level3
            if n is None or g[v] + heuristic(v) < g[n] + heuristic(n):  #level4
                n = v  #level3


        if n is None:  #level3
            print("Path does not exist!")  #level4
            return None  #level3


        if n == stop_node:  #level3
            path = []  #level4
            while parents[n] != n:  #level4
                path.append(n)  #level5
                n = parents[n]  #level4
            path.append(start_node)  #level4
            path.reverse()  #level4
            print("Path found:", path)  #level4
            return path  #level3


        for (m, weight) in get_neighbors(n):  #level3
            if m not in open_set and m not in closed_set:  #level4
                open_set.add(m)  #level5
                parents[m] = n  #level5
                g[m] = g[n] + weight  #level5
            else:  #level4
                if g[m] > g[n] + weight:  #level5
                    g[m] = g[n] + weight  #level6
                    parents[m] = n  #level5
                    if m in closed_set:  #level6
                        closed_set.remove(m)  #level7
                        open_set.add(m)  #level7
        open_set.remove(n)  #level3
        closed_set.add(n)  #level3


    print("Path does not exist!")  #level2
    return None  #level1


# Call A* algorithm
path = aStarAlgo('A', 'G')  #level1


# Create a directed graph using NetworkX
G = nx.DiGraph()  #level1


# Add edges with weights
for node in Graph_nodes:  #level2
    for neighbor, weight in Graph_nodes[node]:  #level3
        G.add_edge(node, neighbor, weight=weight)  #level4


# Draw the graph
pos = nx.spring_layout(G)  # Positioning of nodes  #level1
plt.figure(figsize=(8, 6))  #level2
nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', 
        node_size=2000, font_size=10, font_weight='bold')  #level2


# Draw edge labels
edge_labels = {(u, v): d['weight'] for u, v, d in G.edges(data=True)}  #level2
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12)  #level2


# Highlight the shortest path
if path:  #level2
    path_edges = list(zip(path, path[1:]))  #level3
    nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', 
                           width=2.5)  #level3


plt.title("Graph Representation with A* Algorithm Path")  #level2
plt.show()  #level2
