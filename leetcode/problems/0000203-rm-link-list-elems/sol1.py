# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head == None:
            return None

        if head.next == None and head.val == val:
            return None

        if head.next == None and head.val != val:
            return head

        dummyHead = ListNode(0)
        dummyHead.next = head

        current = head
        prev = dummyHead

        while current:
            if current.val == val:
                prev.next = current.next
                current = current.next

            else:
                current = current.next
                prev = prev.next

        return dummyHead.next
