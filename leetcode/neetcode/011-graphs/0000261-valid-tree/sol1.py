# verified only on neetcode

def validTree(self, n: int, edges: List[List[int]]) -> bool:
    if n - 1 != len(edges): # check cycles
        return False
    
    if n == 1 and len(edges) == 0: # base case: vertex is a tree itself
        return True
    
    # check if tree is one big connected component
    adjList = {}
    for vert1, vert2 in edges:
        if vert1 in adjList:
            adjList[vert1].append(vert2)
        else:
            adjList[vert1] = [vert2]
        
        if vert2 in adjList:
            adjList[vert2].append(vert1)
        else:
            adjList[vert2] = [vert1]
    
    visited = set()
    def dfs(vertex):
        if vertex not in visited:
            visited.add(vertex)
        
        if vertex in adjList:
            for nextVertex in adjList[vertex]:
                if nextVertex not in visited:
                    dfs(nextVertex)

    for item in adjList:
        dfs(item)
        break

    if len(visited) == n:
        return True
    
    return False