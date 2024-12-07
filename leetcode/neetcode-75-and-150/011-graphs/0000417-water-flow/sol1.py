class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ROW_LENGTH, COL_LENGTH = len(heights), len(heights[0])
        pacificVisited, atlanticVisited = set(), set()
        pacificBorder, atlanticBorder = [],[]
        offsets = [(0,1), (1,0), (-1,0), (0,-1)]
        queue = []
        result = []
        
        for a in range(ROW_LENGTH):
            pacificBorder.append((a, 0))
            atlanticBorder.append((a, COL_LENGTH - 1))
        
        for b in range(COL_LENGTH):
            pacificBorder.append((0, b))
            atlanticBorder.append((ROW_LENGTH - 1, b))
        
        def bfs(x,y,visited):
            queue.append((x,y))
            
            while len(queue) > 0:
                x,y = queue.pop(0)
                
                for offsetX, offsetY in offsets:
                    newX = x + offsetX
                    newY = y + offsetY

                    if newX >= 0 and newX < ROW_LENGTH and newY >= 0 and newY < COL_LENGTH and heights[x][y] <= heights[newX][newY] and (newX, newY) not in visited:
                        queue.append((newX, newY))
                        visited.add((newX, newY))
        
        for x,y in pacificBorder:
            if (x,y) not in pacificVisited:
                queue = []
                pacificVisited.add((x,y))
                bfs(x,y,pacificVisited)
        
        for x,y in atlanticBorder:
            if (x,y) not in atlanticVisited:
                queue = []
                atlanticVisited.add((x,y))
                bfs(x,y,atlanticVisited)
            
        for cell in pacificVisited:
            if cell in atlanticVisited:
                result.append([cell[0], cell[1]])
        
        return result