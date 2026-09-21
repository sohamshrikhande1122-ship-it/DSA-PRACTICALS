#insertion and duplicate handling

# 1. Define the Node class first
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# 2. Your SimpleBST class
class SimpleBST:
    def __init__(self):
        self.root = None
        
    def insert(self, node, data):
        if node is None:
            return Node(data)
        if data < node.data:
            node.left = self.insert(node.left, data)
        elif data > node.data:
            node.right = self.insert(node.right, data)
        else:
            print(f"Duplicate {data} ignored.")
        return node


# 3. Test usage
bst = SimpleBST()
bst.root = bst.insert(bst.root, 20)
bst.root = bst.insert(bst.root, 20) # Triggers duplicate check