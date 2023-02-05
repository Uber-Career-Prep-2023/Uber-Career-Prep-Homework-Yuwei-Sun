# Yuwei Sun UCP
# MissingInteger

"""
Given an integer n and a sorted array of integers of size n-1 which contains all but one of the integers in the range
1-n, find the missing integer.

Input Array: [1, 2, 3, 4, 6, 7]
Input n: 7
Output: 5

Input Array: [1]
Input n: 2
Output: 2

Input Array: [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12]
Input n: 12
Output: 9

"""

# for loop, minus method
# edge case: head miss and trail miss
# assume: 1. the miss one should larger than head, which mean head miss is not exist 2. we only use positive integer

def findMiss(arr,n):
    if arr[-1] != n:
        return n
    for i in range(1,len(arr)):
        if arr[i] - arr[i-1] > 1:
            return arr[i] - 1

    return 0 # assume 0 means "not exist"

if __name__ == '__main__':
    print(findMiss([1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12],12))


"""
Time: 4 mins

Time-complexity: O(N), where N is the length of arr
Space-complexity: O(1)
"""



