n, e = map(int, raw_input().split())

nodes = set([i for i in range(1,n+1)])
edges = []

for i in range(e):
    edges.append(map(int, raw_input().split()))

ni = int(input())
    
def grafica(ln, le):
    v = [[] for i in range(len(ln))]
    i = 0
    for a in le:
        v[a[0]-1].append((a[1],a[2]))
        v[a[1]-1].append((a[0],a[2]))
    return v
                 
def small_edge(rs, ur, v):
    min = float("inf")
    small = ()
    c = 1
    for i in v:
        for j in i:
            if (j[0] in ur) and (c in rs):
                if j[1] < min:
                    min = j[1]
                    small = j
        c+=1
    return small

def prim(ur, le, i):
    rs = dict()
    rs[i] = i
    peso = 0
    v = grafica(ur,le)
    ur.remove(i)
    while len(ur) > 0:
        e = small_edge(rs, ur, v)
        peso += e[1]
        ur.remove(e[0])
        rs[e[0]] = e[0]
    return peso
                 
print prim(nodes, edges, ni)
        
