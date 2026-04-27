import matplotlib.pyplot as plt
import networkx as nx
import heapq

def astar(graph, heuristic, start, goal):
    open_list = []
    heapq.heappush(open_list, (heuristic[start], start))
    g_score = {start:0}
    parent = {start:None}
    
    while open_list:
        _,current = heapq.heappop(open_list)
        if current==goal:
            path = []
            while current:
                path.append(current)    
                current = parent[current]
            path.reverse()
            print("Path: ", path)
            print("Cost: ",g_score[goal])
            return path

        for neighbour, weight in graph[current]:
            new_cost = g_score[current]+weight
            if neighbour not in g_score or new_cost < g_score[neighbour]:
                g_score[neighbour] = new_cost
                priority = new_cost + heuristic[neighbour]
                heapq.heappush(open_list, (priority, neighbour))
                parent[neighbour] = current
    print("No Path Found")
    return None

def draw_graph(graph, path = None):
    G = nx.DiGraph()
    for node in graph:
        for neighbour, weight in graph[node]:
            G.add_edge(node, neighbour, weight = weight)
    pos = nx.spring_layout(G)
    plt.figure(figsize=(8,6))
    nx.draw(G, pos, with_labels = True, node_color = 'lightblue', node_size = 2000)
    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels = labels)

    if path:
        edges = list(zip(path, path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist = edges, edge_color = 'red', width = 3)
    
    plt.title("A* Search Algorithm")
    plt.show()

graph = {
    'A' : [('B', 2), ('E', 3)],
    'B' : [('C',1), ('G',2)],
    'C' : [],
    'E' : [('D', 6)],
    'D' : [('G',1)],
    'G' : []
}

heuristic = {
    'A': 11, 'B':6, 'C':99, 'D':1, 'E':7, 'G':0
}

path = astar(graph, heuristic, 'A', 'G')
draw_graph(graph, path)
