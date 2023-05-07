"""
time: 45 mins
average time complexity is O(logn) where n is number of nodes. worst case is O(n). Space complexity is O(n)?
I use BFS order
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.
def LeftView(root):
    result = []
    level = [root]

    while level:
        result.append( level[0].val )
        next_level = []
        # traverse get store each left most node
        for node in level:
            if node.left:
                next_level.append( node.left )
            if node.right:
                next_level.append( node.right )

        level = next_level # ? collection or not?

    return result

if __name__ == '__main__':

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(5)
    print(LeftView(root))
