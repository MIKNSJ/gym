# non-original solution

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        sum = [root.val]

        def maxSubPathSum(curr: Optional[TreeNode]) -> int:
            if curr == None:
                return 0
            
            left = max(maxSubPathSum(curr.left), 0)
            right = max(maxSubPathSum(curr.right), 0)
            
            sum[0] = max(sum[0], curr.val + left + right)
            
            return curr.val + max(left, right)
        
        maxSubPathSum(root)
        return sum[0]