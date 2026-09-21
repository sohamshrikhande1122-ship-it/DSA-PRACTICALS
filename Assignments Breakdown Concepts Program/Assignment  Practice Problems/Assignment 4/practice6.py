#Tree depth calculation

def depth(self, node):
        if node is None:
            return 0
        return max(self.depth(node.left), self.depth(node.right)) + 1