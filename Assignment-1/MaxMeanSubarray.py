# Yuwei Sun UCP
# MaxMeanSubarray

"""
Given an array of integers and an integer, k, find the maximum mean of a subarray of size k.

Input Array: [4, 5, -3, 2, 6, 1]
Input k = 2
Output: 4.5

Input Array: [4, 5, -3, 2, 6, 1]
Input k = 3
Output: 3

Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1]
Input k = 3
Output: 1

Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1, 6]
Input k = 5
Output: 1

"""
# solution: slide window, Max-tracer, pre-calculation
def findMax(arr,k):
    sum = 0
    left_pointer= 0
    right_pointer = 1
    # edge case
    if k == 0:
        return None
    if k == 1:
        return max(arr)

    for j in range( k ):
        sum += arr[j] # sum is value of first group
    temp_sum = sum
    right_pointer = k # update right pointer
    while right_pointer < len(arr):
        temp_sum = temp_sum + arr[right_pointer] - arr[left_pointer]
        if temp_sum > sum:
            sum = temp_sum
        right_pointer += 1
        left_pointer += 1
    result = sum / k
    return result



if __name__ == '__main__':
    arr1 = [1, 1, 1, 1, -1, -1, 2, -1, -1, 6]
    k = 5
    print(findMax(arr1,k))


"""
I spend 11 minutes on this question. 
Bug1: use "sum" rather than "temp_sum" in line 41. And I use print to print out temp_sum value and fix it.

Time-Complexity is O(N), where N is length of array
Space_Complexity is O(1)

"""