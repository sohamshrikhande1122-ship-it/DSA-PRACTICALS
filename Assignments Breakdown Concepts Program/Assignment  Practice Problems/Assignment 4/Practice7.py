#Mirror image transformation

def mirror(self, node):
        if node:
            node.left, node.right = node.right, node.left
            self.mirror(node.left)
            self.mirror(node.right)