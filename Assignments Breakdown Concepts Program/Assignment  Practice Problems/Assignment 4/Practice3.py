#Search operation

def search(self, node, key):
        if node is None or node.data == key:
            return node is not None
        if key < node.data:
            return self.search(node.left, key)
        return self.search(node.right, key)