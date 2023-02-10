# Yuwei Sun UCP
# TwoSum

"""

Given an array of integers and a target integer, k, return the number of pairs of integers in the array that sum to k.
In each pair, the two items must be distinct elements (come from different indices in the array).

Input Array: [1, 10, 8, 3, 2, 5, 7, 2, -2, -1]
Input k: 10
Output: 3
(Pairs: (8, 2), (8, 2), (3, 7))

Input Array: [1, 10, 8, 3, 2, 5, 7, 2, -2, -1]
Input k: 8
Output: 4
(Pairs: (10, -2), (3, 5), (1, 7))

Input Array: [4, 3, 3, 5, 7, 0, 2, 3, 8, 6]
Input k: 5
Output: 6
(Pairs: (4, 2), (0, 6), (3, 3), (3, 3), (3, 3))

Input Array: [4, 3, 3, 5, 7, 0, 2, 3, 8, 6]
Input k: 1

"""


# map

def twosumpair(arr,k):
    answer_dict = {} # store answer, like 10 -> 8+2
    num_dict = {} # store frequency of a number
    result = 0
    for i in arr:
        if i not in answer_dict:
            answer_dict[i] = k-i

    for j in arr:
        if j not in num_dict:
            num_dict[j] = 1
        else:
            num_dict[j] += 1

    for m in answer_dict.keys():
        if answer_dict[m] in num_dict and num_dict[m] > 0:
            if answer_dict[m] != m or num_dict[m] > 1: # number can't pair with itself
                result += num_dict[answer_dict[m]]
            num_dict[answer_dict[m]] = 0
    return result


if __name__ == '__main__':
    print(twosumpair([4, 3, 3, 5, 7, 0, 2, 3, 8, 6],5))


"""
Time: 40 mins
bug 1: line 47. I ignore the number can't pair with itself before. And fix it by check frequency of this number

Wrong 1: fail in case 3

time-complexity: O(N) where N is length of input array
space-complexity: O(2N) where N is length of input array
"""