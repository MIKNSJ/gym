class Solution:
    def buildSubTree(self, preorder: List[int], inorder: List[int], inorderMap: Dict[int, int], startIdx: int, endIdx: int) -> Optional["TreeNode"]:
        if startIdx > endIdx:
            return None
        else:
            root = TreeNode(preorder.pop(0))
            print(root.val)
            mid = inorderMap[root.val]
            root.left = self.buildSubTree(preorder, inorder, inorderMap, startIdx, mid - 1)
            root.right = self.buildSubTree(preorder, inorder, inorderMap, mid + 1, endIdx)
            return root


    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorderMap = {}

        for i in range(len(inorder)):
            inorderMap[inorder[i]] = i

        return self.buildSubTree(preorder, inorder, inorderMap, 0, len(preorder) - 1)