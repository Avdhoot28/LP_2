Graph = {}
Graph['A'] = ['B', 'C']
Graph['B'] = ['D']
Graph['C'] = ['E', 'F', 'G']
Graph['G'] = ['H', 'I']

#            A
#          /   \
#         C     B
#      /  |  \    \
#     G   E   F    D
#    / \
#   H   I 
  

def bfs(Graph):
    first = list(Graph.keys())[0]
    Queue = [first]
    visited = []
    while(Queue):
        a = Queue[0]
        visited.append(a)
        if(a in Graph):
            for value in Graph[a]:
                if(value not in visited):
                    Queue.append(value)
        Queue.pop(0)
    print(visited)

def dfs(Graph):
    Stack = []
    first = list(Graph.keys())[0]
    Stack.append(first)
    visited = []

    while(Stack):
        vertex = Stack.pop()
        if vertex in visited:
            continue
        visited.append(vertex)
        if vertex in Graph:
            for neighbor in Graph[vertex]:
                Stack.append(neighbor)

    print(visited)



while(True):
    print("1. BFS on a graph \n2. DFS on a graph \nExit")
    a=int(input())
    if(a==1):
        print()
        print("BFS - ")
        bfs(Graph)
    elif(a==2):
        print()
        print("DFS - ")
        dfs(Graph)
    else:
        print("Done!")
        break


