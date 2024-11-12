class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        sum = [0]

        def calcPathSum(curr: TreeNode, sum: List[int], str_sum: str) -> None:
            if not curr:
                return None

            str_sum+=str(curr.val)

            if curr.left == None and curr.right == None:
                sum[0]+=int(str_sum)
                str_sum = ""

            calcPathSum(curr.left, sum, str_sum)
            calcPathSum(curr.right, sum, str_sum)

        calcPathSum(root, sum, "")
        return sum[0]