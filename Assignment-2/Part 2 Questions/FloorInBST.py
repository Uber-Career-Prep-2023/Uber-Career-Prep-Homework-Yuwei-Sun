"""
time: 37 mins
time: O(logn) n is num of node, worst is O(n). Space is O(h) where h is heigh of tree
I use the idea of binary search and pre-order
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Given a target numeric value and a binary search tree, return the floor
# (greatest element less than or equal to the target) in the BST.
def FloorInBST(root, target):
    if root.val == target: # directly found
        return root.val

    elif root.val > target:
        return FloorInBST(root.left, target)

    else:
        right = FloorInBST(root.right, target)
        # return a bigger value
        if right is not None:
            return right
        else:
            return root.val
if __name__ == '__main__':
    root = TreeNode( 10 )
    root.left = TreeNode( 8 )
    root.left.left = None
    root.left.right = TreeNode( 9 )
    root.right = TreeNode( 16 )
    root.right.left = TreeNode( 13 )
    root.right.right = TreeNode( 17 )
    root.right.right.right = TreeNode( 20 )
    print(FloorInBST(root,13))
