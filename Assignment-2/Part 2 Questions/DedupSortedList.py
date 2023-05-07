"""
time: 23 mins
time complexityO(n) as n is #nodes of original SLL. Space complexity is O(1)
*
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


# Given a sorted singly linked list, remove any duplicates so that no value appears more than once.
# As it is a sort linked list, all duplicates item should appear together
def DedupSortedList(head):
    current = head
    while current and current.next:
        if current.val == current.next.val:
            # jump the duplicates
            current.next = current.next.next
        else:
            current = current.next
    return head


if __name__ == '__main__':
    print("Hello World!")
    list = SingleListNode(1)
    list.next= SingleListNode(2)
    list.next.next = SingleListNode( 2 )
    list.next.next.next = SingleListNode( 4 )
    list.next.next.next.next = SingleListNode( 5 )
    list.next.next.next.next.next = SingleListNode( 5 )
    list.next.next.next.next.next.next = SingleListNode( 5 )
    list.next.next.next.next.next.next.next = SingleListNode( 10)
    list.next.next.next.next.next.next.next.next = SingleListNode( 10)
    printSingleLinkedList(list)
    newlist = DedupSortedList(list)
    printSingleLinkedList(newlist)

