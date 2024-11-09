# =================================================================================================================== #
#                                                                                                                     |
#     LeetEnv                                                                                                         |
#     Version 1.1                                                                                                     |
#     Test LeetCode problems from your editor!                                                                        |
#                                                                                                                     |
#                                                                                                                     |
#     Latest python complier version: 3.10.2                                                                          |
#     Latest OS build: WSL2 Ubuntu 22.04.4 LTS                                                                        |
#                                                                                                                     |
#                                                                                                                     |
#     Created by @MIKNSJ 2024                                                                                         |
#                                                                                                                     |
# =================================================================================================================== #
#X
#X
#X
#X
#X
# ========= IMPORT STATEMENTS ======================================================================================= #
# import array                                                                                                                     
# import bisect                                                                                                                     
# import math
# import collections
# import sortedcontainers
from typing import Optional, List
#
#
#
#
# =================================================================================================================== #
#X
#X
#X
#X
#X
# ========== DATA STRUCTURES ======================================================================================== #
# ========== SINGLY LINKED LIST ===================================================================================== #
class ListNode:
    # SET UP A LIST NODE OBJECT
    def __init__(self, val: Optional[int] = None, next: Optional["ListNode"] = None, nodes: Optional[List[int]] = None) -> None:
        if val == None and nodes == None:
            self.val = 0
            self.next = next

        elif val != None and nodes == None:
            self.val = val
            self.next = next

        else:
            self.val = nodes[0]
            self.next = next

            if (nodes != None):
                curr = self
                for i in range(1, len(nodes)):
                    curr.next = ListNode(val=nodes[i])
                    curr = curr.next


# PRINTS OUT THE SINGLY LINKED LIST
def printList(head) -> None:
    size = 0

    if head == None:
        print(f'[]\nSize: {size}')
        return

    current = head
    while current:
        if (current.next != None):
            print(f'[{current.val}]', end=" -> ")
        else:
            print(f'[{current.val}]')

        current = current.next
        size+=1

    print(f'Size: {size}')
# ========== END OF SINGLY LINKED LIST ============================================================================== #
#X
#X
#X
# ========== TREES ================================================================================================== #
class TreeNode:
    # SET UP A TREE NODE OBJECT
    def __init__(self, val: Optional[int], left: Optional["TreeNode"] = None, right: Optional["TreeNode"] = None, nodes: Optional[List[Optional[int]]] = None) -> None:
        if val == None and nodes == None:
            self.val = 0
            self.left = left
            self.right = right

        elif val != None and nodes == None:
            self.val = val
            self.left = left
            self.right = right

        else:
            self.val = nodes[0]
            self.left = left
            self.right = right

            if (nodes != None):
                queue = []
                queue.append(self)
                nodes.pop(0)

                while queue:
                    if (len(nodes) == 0):
                        break

                    current = queue.pop(0)

                    leftChildVal = nodes.pop(0)
                    if (leftChildVal != None):
                        current.left = TreeNode(leftChildVal)
                        queue.append(current.left)

                    rightChildVal = nodes.pop(0)
                    if (rightChildVal != None):
                        current.right = TreeNode(rightChildVal)
                        queue.append(current.right)


# PRINTS OUT THE TREE
def printTree(root) -> None:
    size = 0

    if root == None:
        print(f'[]\nSize: {size}')
        return

    tree = []
    tree.append(root.val)
    queue = []
    queue.append(root)
    size+=1

    while queue:
        current = queue.pop(0)

        if (current.left):
            queue.append(current.left)
            tree.append(current.left.val)
            size+=1
        else:
            tree.append(None)

        if (current.right):
            queue.append(current.right)
            tree.append(current.right.val)
            size+=1
        else:
            tree.append(None)
    
    for i in range(len(tree) - 1, -1, -1):
        if (tree[i] == None):
            tree.pop(i)
        else:
            break

    print(f'{tree}\nSize: {size}')
# ========== END OF TREES =========================================================================================== #
#X
#X
#X
# ========== INTERVALS ============================================================================================== #
# SET UP A INTERVAL OBJECT:
class Interval:
    def __init__(self, start: int, end: int) -> None:
        self.start = start
        self.end = end


# CHECK IF TWO INTERVALS INTERSECTION
# THIS ASSUMES THAT AN INTERVAL THAT STARTS AFTER ONE ENDS AT THE SAME TIME IS OKAY
def checkIntersection(intervalA: Interval, intervalB: Interval) -> None:
    if (intervalA.end > intervalB.start):
        print("There is an intersection between these two intervals. Interval A crosses Interval B.")
    elif (intervalB.end > intervalA.start):
        print("There is an intersection between these two intervals. Interval B crosses Interval A.")
    else:
        print("There is no intersection between these two intervals.")
# ========== END OF INTERVALS ======================================================================================= #
# ========== END OF DATA STRUCTURES ================================================================================= #
#X
#X
#X
#X
#X
#X      
# ========== ADDITIONAL HELPER FUNCTIONS ============================================================================ #
# REPLACE THIS LINE AND DEFINE THEM HERE




# ========== END OF HELPER FUNCTIONS ================================================================================ #
#X
#X
#X
#X
#X
# ========== SOLUTION =============================================================================================== #
# ========== PASTE YOUR LEETCODE FUNCTION IMPLMENTATION BELOW ======================================================= #
class Solution:
    ...




# ========== END OF SOLUTION ======================================================================================== #
#X
#X
#X
#X
#X
# ========== RUN ==================================================================================================== #
# ========== YOUR =================================================================================================== #
# ========== CODE =================================================================================================== #
# ========== AND ==================================================================================================== #
# ========== ADD TEST CASES AS NEEDED BELOW ========================================================================= #
def main():
    solution = Solution()
    print("Find and delete this line.")


# ========== TEST CASE ONE ========================================================================================== #
# INPUT:
# EXPECTED:
# ACTUAL:
# REPLACE WITH CODE HERE AND BELOW


# ========== TEST CASE TWO ========================================================================================== #
# INPUT:
# EXPECTED:
# ACTUAL:
# REPLACE WITH CODE HERE AND BELOW


# ========== TEST CASE THREE ======================================================================================== #
# INPUT:
# EXPECTED:
# ACTUAL:
# REPLACE WITH CODE HERE AND BELOW


# ========== TEST CASE FOUR ========================================================================================= #
# INPUT:
# EXPECTED:
# ACTUAL:
# REPLACE WITH CODE HERE AND BELOW


# ========== TEST CASE FIVE ========================================================================================= #
# INPUT:
# EXPECTED:
# ACTUAL:
# REPLACE WITH CODE HERE AND BELOW


# ========== END OF RUN ============================================================================================= #
#X
#X
#X
# ========== DO NOT TOUCH =========================================================================================== #
# ========== PREVENTS EXECUTING OTHER MAIN FUNCTIONS FROM IMPORTED FILES ============================================ #
if __name__ == "__main__":
    main()
#X
#X
#X
#X
#X
# ========== END OF FILE ============================================================================================ #
