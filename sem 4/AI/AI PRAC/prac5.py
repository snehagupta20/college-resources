# code by sneha gupta 2021UCA1859

class Graph:
    def __init__(self, vertices, edges):
        self.vertices = vertices
        self.edges =edges

    def is_valid_coloring (self, variable_assignments): 
        for vertex, color in variable_assignments.items(): 
            if color is None:
                return False
                
            for neighbor in self.edges [vertex]:
                if variable_assignments [neighbor] == color: 
                    return False
                
        return True
    
def backtrack (variable_assignments, domains, graph):
    if all (variable_assignments.values()):
        if graph.is_valid_coloring (variable_assignments):
            return variable_assignments
        else:
            return None
        
    unassigned_variables = [variable for variable, value in variable_assignments.items() if value is None] 
    variable = unassigned_variables[0]

    for value in domains [variable]:
        variable_assignments [variable] = value
        domains_copy =domains.copy()
        for unassigned_variable in unassigned_variables: 
            if unassigned_variable != variable: 
                domains_copy [unassigned_variable] = {value}
        result = backtrack (variable_assignments, domains_copy, graph)
        if result is not None:
            return result
        variable_assignments[variable] = None
    return None
            
if __name__=='__main__':
    vertices = [1, 2, 3, 4]
    edges = {
        1: [2, 3],
        2: [1, 3, 4],
        3: [1, 2, 4],
        4: [2, 3]
    }
    graph =Graph (vertices, edges)

    variable_assignments = {vertex: None for vertex in vertices}
    domains={vertex: {1, 2, 3} for vertex in vertices}
    result = backtrack (variable_assignments, domains, graph) 
    print(result) 

