#parent child mapping and leaf identification

def leafNodes(self, node):
        if node:
            if not node.left and not node.right:
                print(node.data, end=" ")
            self.leafNodes(node.left)
            self.leafNodes(node.right)