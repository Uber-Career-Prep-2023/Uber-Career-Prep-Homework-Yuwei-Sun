"""
time： 23mins
time complexity is O(n) where n is length of SLL. Space complexity is O(1)
slow and fast pointer has been use

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

# Given a singly linked list, move the nth from the last element to the front of the list.
def MoveNthLastToFront(head,k):
    # find the nth node from the end
    slow = fast = head
    for i in range(k):
        if not fast:
            return head  # len < k
        fast = fast.next
    if not fast:
        return head  # n equals length of list
    while fast.next:
        slow = slow.next
        fast = fast.next

    nth_node = slow.next
    slow.next = nth_node.next

    nth_node.next = head
    head = nth_node

    return head

if __name__ == '__main__':
    print("Hello World!")
    list = SingleListNode(15)
    list.next= SingleListNode(2)
    list.next.next = SingleListNode( 8 )
    list.next.next.next = SingleListNode( 7 )
    list.next.next.next.next = SingleListNode( 20 )
    list.next.next.next.next.next = SingleListNode( 9 )
    list.next.next.next.next.next.next = SingleListNode(11 )
    list.next.next.next.next.next.next.next = SingleListNode( 6)
    list.next.next.next.next.next.next.next.next = SingleListNode( 19)
    printSingleLinkedList(list)
    print()
    newlist = MoveNthLastToFront(list,2)
    printSingleLinkedList(newlist)