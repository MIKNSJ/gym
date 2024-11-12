# non-original solution

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def calcPathSum(curr: TreeNode, sum: int) -> bool:
            if not curr:
                return False

            sum+=curr.val
            if curr.left == None and curr.right == None:
                return sum == targetSum

            return calcPathSum(curr.left, sum) or calcPathSum(curr.right, sum)

        return calcPathSum(root, 0)