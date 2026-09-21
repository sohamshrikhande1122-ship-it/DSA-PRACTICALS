#Node initialization and bst setup

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Quick test
root = Node(10)
print("Root node value:", root.data)