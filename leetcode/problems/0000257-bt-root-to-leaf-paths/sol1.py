class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        validPaths = []
        path = []

        def findPaths(curr: TreeNode) -> None:
            if not curr:
                return False

            path.append(curr.val)

            if curr.left == None and curr.right == None:
                path_str = ""
                for i in range(len(path)):
                    if (i != len(path) - 1):
                        path_str = path_str + str(path[i]) + "->"
                    else:
                        path_str = path_str + str(path[i])

                validPaths.append(path_str)

            findPaths(curr.left)
            findPaths(curr.right)
            path.pop(len(path) - 1)

        findPaths(root)
        return validPaths