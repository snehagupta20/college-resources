#importing the PriorityQueue class from the queue module
from queue import PriorityQueue
v = 14
graph = [[] for i in range(v)]
 
# Function For Implementing Best First Search
# Gives output path having lowest cost
 
#actual_Src, which is the starting node, 
# target, which is the node we want to reach, and 
# n, which is the total number of nodes in the graph.
def best_first_search(actual_Src, target, n):

    #visited that keeps track of which nodes have been visited.
    visited = [False] * n

    #PriorityQueue object pq, and adds the starting node to it with a cost of 0
    pq = PriorityQueue()
    pq.put((0, actual_Src))
    visited[actual_Src] = True
     
    while pq.empty() == False:
        u = pq.get()[1]
        # Displaying the path having lowest cost
        print(u, end=" ")

        #If this node is the target node, the function breaks out of the loop
        if u == target:
            break
 
        for v, c in graph[u]:
            if visited[v] == False:
                visited[v] = True
                pq.put((c, v))
    print()
 
# Function for adding edges to graph
 
 
#The addedge function is used to add edges to the graph, 
# and takes three arguments: x, y, and cost. 
# It appends a tuple (y, cost) to the graph[x] list and vice versa.
def addedge(x, y, cost):
    graph[x].append((y, cost))
    graph[y].append((x, cost))
 
 
# The nodes shown in above example(by alphabets) are
# implemented using integers addedge(x,y,cost);
addedge(0, 1, 3)
addedge(0, 2, 6)
addedge(0, 3, 5)
addedge(1, 4, 9)
addedge(1, 5, 8)
addedge(2, 6, 12)
addedge(2, 7, 14)
addedge(3, 8, 7)
addedge(8, 9, 5)
addedge(8, 10, 6)
addedge(9, 11, 1)
addedge(9, 12, 10)
addedge(9, 13, 2)
 
source = 0
target = 9
best_first_search(source, target, v)
 
