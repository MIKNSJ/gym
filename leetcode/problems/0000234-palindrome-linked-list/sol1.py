# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        current = head
        contents = []
        reverse_contents = []

        while current:
            contents.append(current.val)
            current = current.next

        for i in range(len(contents)):
            reverse_contents.append(contents[len(contents) - 1 - i])

        if contents == reverse_contents:
            return True
        else:
            return False