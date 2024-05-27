# YYYY-MM-DD

import array
import bisect
import math
import collections
import sortedcontainers



# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Prints out the list
def print_list(head: ListNode) -> None:
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "\n")
        current = current.next



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Prints out the tree
def print_tree(root: TreeNode) -> None:
    if not root:
        return
    
    queue = collections.deque([(root, 0)])  # (node, level)
    current_level = 0
    level_nodes = []
    
    while queue:
        node, level = queue.popleft()
        
        if level != current_level:
            print(' '.join(map(str, level_nodes)))
            current_level = level
            level_nodes = []
        
        level_nodes.append(node.val)
        
        if node.left:
            queue.append((node.left, level + 1))
        if node.right:
            queue.append((node.right, level + 1))
    
    # Print the last level
    if level_nodes:
        print(' '.join(map(str, level_nodes)))



class Solution:
    ...



def main():
    solution = Solution()
    ...



if __name__ == "main":
    main()