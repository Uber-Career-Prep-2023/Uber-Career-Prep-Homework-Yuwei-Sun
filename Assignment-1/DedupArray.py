# Yuwei Sun UCP
# DedupArray

"""

Given a sorted array of non-negative integers, modify the array by removing duplicates so each element only
appears once. If arrays are static (aka, not dynamic/resizable) in your language of choice, the remaining elements
should appear in the left-hand side of the array and the extra space in the right-hand side should be padded with -1s.

Input Array: [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
Modified Array: [1, 2, 3, 4]
or [1, 2, 3, 4, -1, -1, -1, -1, -1, -1] (depending on language)

Input Array: [0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15]
Modified Array: [0, 1, 4, 5, 8, 9, 10, 11, 15]
or [1, 4, 5, 8, 9, 10, 11, 15, -1, -1, -1, -1, -1] (depending on language)

Input Array: [1, 3, 4, 8, 10, 12]
Modified Array: [1, 3, 4, 8, 10, 12]
"""

# list->set, set-> list
#

def deduparr(arr):
    temp_set = set(arr)
    temp_list = list(temp_set)
    for i in range(len(temp_list)):
        arr[i] = temp_list[i]
    for j in range(len(arr),len(temp_list),-1):
        arr.pop()


if __name__ == '__main__':
    arr = [1, 3, 4, 8, 10, 12]
    deduparr(arr)
    print(arr)


"""
Time: 7 mins
First try, use deepcopy but we have import copy.

time-complexity: O(N), where N is length of input arr
space-complexity: O(2N), where N is length of input arr
"""