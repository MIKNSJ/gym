# verified only on neetcode

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:  
        if len(edges) == 0:
            return n
        
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
        components = 0
        def dfs(vertex):
            if vertex not in visited:
                visited.add(vertex)
            
            if vertex in adjList:
                for nextVertex in adjList[vertex]:
                    if nextVertex not in visited:
                        dfs(nextVertex)

        for i in range(n - 1):
            if i not in visited:
                dfs(i)
                components+=1

        return components