class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = {}
        for course, precourse in prerequisites:
            if course in adjList:
                adjList[course].append(precourse)
            else:
                adjList[course] = [precourse]
                
        UNVISITED = 0
        VISITING = 1
        VISITED = 2
        visitedStates = [UNVISITED] * numCourses
        
        def dfs(currCourse):
            if visitedStates[currCourse] == UNVISITED:
                visitedStates[currCourse] = VISITING
            elif visitedStates[currCourse] == VISITING:
                return False
            else:
                return True
            
            if currCourse in adjList:
                for precourse in adjList[currCourse]:
                    if not dfs(precourse):
                        return False
                    
            visitedStates[currCourse] = VISITED
            
            return True
            
        for course in adjList:
            if not dfs(course):
                return False
        
        return True