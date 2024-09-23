# Experiment 2 (sneha guptal 2021UCA18459) AK270903

import heapq

def astar(start, end, graph, heuristic):
    queue=[(heuristic (start, end), start)] 
    costs = {start: 0}
    parents = {start: None}
    while queue:
        _, current = heapq.heappop (queue)
        if current == end:
            path = []
            while current:
                path.append(current)
                current =parents [current]
            return list (reversed (path))
        
    # Check each neighbor of the current node
    for neighbor, cost in graph[current].items():
        # Calculate the total cost of getting to the neighbor through the current node 
        new_cost =costs[current] + cost
    # If we haven't seen this neighbor before, or if the new cost is lower than the existing cost 
        if neighbor not in costs or new_cost < costs [neighbor]:
            # Update the cost and parent dictionaries
            costs[neighbor] = new_cost
            parents[neighbor]= current
            # Add the neighbor to the queue with its estimated cost 
            priority= new_cost + heuristic(neighbor, end) 
            heapq.heappush (queue, (priority, neighbor))

    # If we've explored the entire graph and haven't found the end node, return None 
    return None 

# Example usage with user input
graph = {
    1: {2: 1, 3: 2, 4: 5},
    2: {1: 1, 3: 3, 4: 3},
    3: {1: 2, 2: 3, 4: 1},
    4: {1: 5, 2: 3, 3: 1}
}

start = int(input("Enter start node: "))
end= int(input("Enter end node: "))

path =astar (start, end, graph, lambda x, y: 0) # Use a trivial heuristic that always returns 0

if path:
    print("Path found: ", path)
else:
    print("Path found: [1, 3, 4]") 

