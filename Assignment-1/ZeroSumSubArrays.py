# Yuwei Sun UCP
# ZeroSumSubArrays

"""
Given an array of integers, count the number of subarrays that sum to zero.

Input Array: [4, 5, 2, -1, -3, -3, 4, 6, -7]
Output: 2
(Subarrays: [5, 2, -1, -3, -3], [-3, 4, 6, -7])

Input Array: [1, 8, 7, 3, 11, 9]
Output: 0

Input Array: [8, -5, 0, -2, 3, -4]
Output: 0
(Subarrays: [0], [8, -5, 0, -2, 3, -4])

"""

# method 1: brute force

def zerosumsubarrays(arr):
    left = 0
    right = 0
    result = 0 #result = []
    sum = 0
    while left <= right and right < len(arr):
        sum += arr[right]
        if sum == 0:
            #result.append(arr[left:right+1])
            result += 1
        right += 1
        if right == len(arr) and left < right:
            left += 1
            sum = 0
            right = left
    return result

if __name__ == '__main__':
    arr = [8, -5, 0, -2, 3, -4]
    print(zerosumsubarrays(arr))

"""
Time: 36 mins
bug1: line33, right == len(arr) rather than len(arr) - 1. If use len(arr) - 1, the program can not add last item of the 
array into sum. Find it by print(arr[right]) in the beginning  of loop.

Time-complexity: O(N!) where N is length of array
Space-complexity: O(4), constant 
"""