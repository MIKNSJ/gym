class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        size = 0

        if root == None:
            return "#empty#"

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
        
        tree_str = ""
        for j in range(len(tree)):
            tree_str+=str(tree[j])
            tree_str+="#"
        
        return tree_str
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "#empty#":
            return None
        
        nodes = []
        val_str = ""
        idx = 0

        while idx < len(data):
            if data[idx] == "#" and val_str != None:
                if (val_str == "None"):
                    nodes.append(None)
                else:
                    nodes.append(int(val_str))

                val_str = ""

            else:
                val_str+=data[idx]

            idx+=1

        root = TreeNode()
        root.val = nodes[0]

        if (nodes != None):
            queue = []
            queue.append(root)
            nodes.pop(0)

            while queue:
                if (len(nodes) == 0):
                    break

                current = queue.pop(0)

                if len(nodes) > 0:
                    leftChildVal = nodes.pop(0)
                    if (leftChildVal != None):
                        current.left = TreeNode(leftChildVal)
                        queue.append(current.left)

                if len(nodes) > 0:
                    rightChildVal = nodes.pop(0)
                    if (rightChildVal != None):
                        current.right = TreeNode(rightChildVal)
                        queue.append(current.right)

        return root