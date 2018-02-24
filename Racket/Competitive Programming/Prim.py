def process(lst):
    real = list()
    for x in lst:
        real.append(int(x))
    return real

def empty(lst):
    return len(lst) == 0

nm = input().split()
num_nodes = int(nm[0])
num_edges = int(nm[1])
graph = dict()
for x in range(num_nodes):
    graph[x+1] = list()
    
for x in range(num_edges):
    edge = process(input().split())
    graph[edge[0]].append((edge[1],edge[2]))

mst = 0
initial = int(input())
reached = list()
reached.append(initial)
unreached = list(graph.keys())
unreached.remove(initial)
while len(unreached) > 0:
    items = list(graph.items())
    minimum = (100001,100001)
    for node, neighbour  in items:
        #if node in reached and neighbour[0] in unreached and neighbour[1] < minimum[1]:
            print(node in reached)
            print(neighbour[0] in unreached)
            print(neighbour[1] < minimum[1])
            # print("Check if")
            # minimum = neighbour
    # mst += minimum[1]
    # print(reached)
    # reached.append(minimum[0])
    # print(unreached)
    # unreached.remove(minimum[0])
print(mst)
