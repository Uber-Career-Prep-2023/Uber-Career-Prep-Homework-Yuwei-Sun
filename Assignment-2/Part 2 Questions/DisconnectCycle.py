"""
time: 40 mins
time complexity is O(n) where n is length of SLL. Space complexity is O(1)
Method:  slow and fast pointer
"""

class SingleListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def printSingleLinkedList(head):
    cursor = head
    while cursor is not None:
        print(cursor.val)
        cursor = cursor.next

# Given a singly linked list, disconnect the cycle, if one exists.
# Assume all input has cycle

# 1 find cycle
# 2. disconnect
def DisconnectCycle(head):

        # traverse and find the cycle
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast: # stop
            break
    else:
        return

    # disconnect cycle
    cursor = head
    while cursor != fast:
        cursor = cursor.next
        fast = fast.next
    while cursor.next != fast:
        cursor = cursor.next
    cursor.next = None
    return head

if __name__ == '__main__':
    print('Hello, World')
    head = SingleListNode( 1 )
    node1 = SingleListNode( 2 )
    node2 = SingleListNode( 3 )
    node3 = SingleListNode( 4 )
    node4 = SingleListNode( 5 )

    head.next = node1
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node2 # cycle
    printSingleLinkedList(DisconnectCycle(head))


