# YYYY-MM-DD

# import array
# import bisect
# import math
# import collections
# import sortedcontainers



# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Prints out the list
def print_list(head: ListNode) -> None:
    if not head:
        print ("[]")
        return

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
        print("[]")
        return

    queue = [root]

    while queue:
        level_size = len(queue)
        for _ in range(level_size):
            node = queue.pop(0)
            print(node.val, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        print()  # Print newline after each level



class Solution:
    ...



def main():
    solution = Solution()
    ...



if __name__ == "main":
    main()