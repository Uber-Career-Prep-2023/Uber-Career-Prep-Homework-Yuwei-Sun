"""
time: 21 mins
time complexity is O(n) where n is length of DLL. Space complexity is O(1)
The property of DDL has been use
"""

class DoubleListNode:
    def __init__(self, value=0, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next

# copy from my hw of data structure and algo
def buildDDL(numbers):
    head = None
    prev_node = None
    for num in numbers:
        current_node = DoubleListNode(num)
        if not head:
            head = current_node
        if prev_node:
            prev_node.next = current_node
            current_node.prev = prev_node
        prev_node = current_node
    return head

# Given a doubly linked list, determine if it is a palindrome.
def IsPalindrome(head):
    trail = head
    while trail.next is not None:
        trail = trail.next

    while head != trail and head.prev != trail:
        if head.value != trail.value:
            return False
        head = head.next
        trail = trail.prev
    return True

if __name__ == '__main__':
    list1 = [9,2,4,2,9]
    head1 = buildDDL(list1)
    print(IsPalindrome(head1))
    list2 = [9,12,4,2,9]
    head2 = buildDDL( list2 )
    print( IsPalindrome( head2 ) )
