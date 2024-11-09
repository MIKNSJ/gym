# This solution is broken on NeetCode.io
# Error: Output returns None instead of TreeNode



# This is APPROACH 1 OUT OF 2. See the other approach below.



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traverse(self, curr: "TreeNode", p: "TreeNode", q: "TreeNode") -> "TreeNode":
        if curr == None:
            return None
        
        if (p.val < curr.val and q.val > curr.val) or (p.val > curr.val and q.val < curr.val):
            return curr

        if p == curr and (curr.left == q or curr.right == q):
            return curr
        
        if q == curr and (curr.left == p or curr.right == p):
            return curr
        
        if p == curr and (curr.val < q.val or curr.val > q.val):
            return curr
        
        if q == curr and (curr.val < p.val or curr.val > p.val):
            return curr

        if (curr.left == p and curr.right == q) or (curr.left == q and curr.right == p):
            return curr

        return self.traverse(curr.left, p, q) or self.traverse(curr.right, p, q)

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val < root.val and q.val > root.val or p.val > root.val and q.val < root.val:
            return root

        if p == root or q == root:
            return root

        return self.traverse(root.left, p, q) or self.traverse(root.right, p, q)





# This is APPROACH 2 OUT OF 2. See the other approach above.
# Alternatively, one could combine the two functions together.
# Still, this condensed approach still fails for the same reason on NeetCode.



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None:
            return None
        
        if (p.val < root.val and q.val > root.val) or (p.val > root.val and q.val < root.val):
            return root

        if p == root and (root.left == q or root.right == q):
            return root
        
        if q == root and (root.left == p or root.right == p):
            return root
        
        if p == root and (root.val < q.val or root.val > q.val):
            return root

        if q == root and (root.val < p.val or root.val > p.val):
            return root

        if (root.left == p and root.right == q) or (root.left == q and root.right == p):
            return root

        return self.lowestCommonAncestor(root.left, p, q) or self.lowestCommonAncestor(root.right, p, q)
              