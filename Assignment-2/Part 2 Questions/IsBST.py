"""
time: 11 mins, I write this before
O(n), because I check a BST so there is not BST property. Space is O(h) where h is heigh of tree
inorder traverse

"""


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Given a binary tree, determine if it is a binary search tree.
def isBST(node, min_val, max_val):
    # if None, we got it
    if node is None:
        return True

    # not in correct interval
    if node.val < min_val or node.val > max_val:
        return False

    # left + right
    return isBST( node.left, min_val, node.val - 1 ) and isBST( node.right, node.val + 1, max_val )

if __name__ == '__main__':
    root = TreeNode(10)
    root.left = TreeNode(8)
    root.right = TreeNode(16)
    root.left.right = TreeNode(9)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode( 17 )
    root.right.right.right = TreeNode( 20 )
    print(isBST(root,float('-inf'),float('inf')))

    root.right.right.right = TreeNode( 15 )
    print( isBST( root, float( '-inf' ), float( 'inf' ) ) )


