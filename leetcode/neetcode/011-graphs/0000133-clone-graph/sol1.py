"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node == None:
            return None

        if node and node.neighbors == None:
            return Node(val=node.val)
        
        root = Node(node.val)
        visited = dict()
        visited[node.val] = root
        queue = []
        queue.append(node)
        
        while len(queue) > 0:
            currNode = queue.pop(0)
            
            if currNode.val not in visited.keys():
                newNode = Node(currNode.val)
                visited[currNode.val] = newNode
                queue.append(currNode)
                currDeepNode = newNode
            else:
                currDeepNode = visited.get(currNode.val)
            
                    
            for i in range(len(currNode.neighbors)):
                if currNode.neighbors[i].val not in visited.keys():
                    newNode = Node(currNode.neighbors[i].val)
                    currDeepNode.neighbors.append(newNode)
                    visited[currNode.neighbors[i].val] = newNode
                    queue.append(currNode.neighbors[i])
                else:
                    existingNode = visited.get(currNode.neighbors[i].val)
                    currDeepNode.neighbors.append(existingNode)
        
        return root