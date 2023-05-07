"""
time: 27 mins
O(n) as n is number of nodes for original tree
I use DFS to traverse the tree
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def print_tree_inorder(node):
    """
    Helper function to print the inorder traversal of a binary tree.
    """
    if node is None:
        return
    print_tree_inorder(node.left)
    print(node.val, end=" ")
    print_tree_inorder(node.right)

# Given a binary tree, create a deep copy. Return the root of the new tree.
# recursive
def copyTree(root):
    if not root:
        return None
    newNode = TreeNode(root.val)
    newNode.left = copyTree(root.left)
    newNode.right = copyTree(root.right)
    return newNode

if __name__ == '__main__':
    root = TreeNode( 1 )
    root.left = TreeNode( 2 )
    root.right = TreeNode( 3 )
    root.left.left = TreeNode( 4 )
    root.left.right = TreeNode( 5 )
    print_tree_inorder( root )
    print()
    new_root = copyTree(root)
    root.val = 6
    print_tree_inorder( root )
    print()
    print_tree_inorder( new_root )