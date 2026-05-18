import networkx as nx
import matplotlib.pyplot as plt

def cost(H, condition, weight = 1):
    costs = {}
    if 'AND' in condition:
        and_nodes = condition['AND']
        and_path = ' AND '.join(and_nodes)
        costs[and_path] = sum(H[node]+weight for node in and_nodes)
    
    if 'OR' in condition:
        or_nodes = condition['OR']
        or_path = ' OR '.join(or_nodes)
        costs[or_path] = min(H[node] + weight for node in or_nodes)
    return costs

def update_cost(H, conditions, weight = 1):
    updated_cost = {}
    main_nodes = list(conditions.keys())
    main_nodes.reverse()

    for node in main_nodes:
        condition = conditions[node]
        print(node, ':', conditions[node], '>>>', cost(H, condition, weight))
        c = cost(H, condition, weight)
        H[node] = min(c.values())
        updated_cost[node] = cost(H, condition, weight)
    return updated_cost

def shortest_route(start, updated_cost, H):
    path = start
    if start not in updated_cost:
        return path
    min_cost = min(updated_cost[start].values())
    best_key = min(updated_cost[start], key = updated_cost[start].get)
    if 'AND' in best_key:
        parts = best_key.split(' AND ')
    elif 'OR' in best_key:
        parts = best_key.split(' OR ')
    else:
        parts = [best_key]

    if len(parts)==1:
        next_node = parts[0]
        path+= ' <-- '+shortest_route(next_node, updated_cost, H)
    else:
        path+= ' <-- ('+best_key+') [ '
        for i in range(len(parts)):
            path+=shortest_route(parts[i],updated_cost,H)
            if i!=len(parts)-1:
                path+= ' + '
        path += ' ] '
    return path

def visualize_graph(conditions):
    G = nx.DiGraph()
    for node, condition in conditions.items():
        if 'AND' in condition:
            for n in condition['AND']:
                G.add_edge(node, n, label = 'AND', color = 'green')
        if 'OR' in condition:
            for n in condition['OR']:
                G.add_edge(node, n, label = 'OR', color = 'blue')
    pos = nx.planar_layout(G)
    labels = nx.get_edge_attributes(G, 'label')
    colors = [G[u][v]['color'] for u,v in G.edges()] 
    plt.figure(figsize = (10,8))
    nx.draw(G, pos, with_labels = True, node_color = 'lightblue', node_size = 2000, font_size = 10,font_weight = 'bold', edge_color = colors, arrows = True)
    nx.draw_networkx_edge_labels(G, pos, edge_labels = labels, font_color = 'red')
    plt.title('AO* Search Algorithm')
    plt.show()

H = {'A':-1, 'B': 5, 'C':2,'D':4,'E':7,'F':9,'G':3,'H':0,'I':0,'J':0}
conditions = {
    'A': {'OR': ['B'], 'AND': ['C','D']},
    'B': {'OR':['E','F']},
    'C': {'OR':['G'],'AND': ['H','I']},
    'D': {'OR':['J']}
}

weight = 1
print("Updated Cost: ")
updatedcost = update_cost(H, conditions, weight)
print("*"*75)
print("Shortest Path: ")
print(shortest_route('A', updatedcost, H))
visualize_graph(conditions)
