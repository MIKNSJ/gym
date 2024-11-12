class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        validPaths = []
        path = []

        def calcPathSum(curr: TreeNode, sum: int) -> None:
            if not curr:
                return False

            sum+=curr.val
            path.append(curr.val)

            if curr.left == None and curr.right == None:
                if sum == targetSum:
                    validPaths.append(path.copy())

            calcPathSum(curr.left, sum)
            calcPathSum(curr.right, sum)
            path.pop(len(path) - 1)

        calcPathSum(root, 0)
        return validPaths