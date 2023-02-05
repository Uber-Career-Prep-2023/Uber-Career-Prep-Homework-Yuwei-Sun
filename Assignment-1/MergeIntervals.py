# Yuwei Sun UCP
# MergeIntervals

"""
Given a list of integer pairs representing the low and high end of an interval, inclusive, return a list in which
overlapping intervals are merged.

Input: [(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]
Output: [(4, 8), (1, 3), (9, 12)]

Input: [(5, 8), (6, 10), (2, 4), (3, 6)]
Output: [(2, 10)]

Input: [(10, 12), (5, 6), (7, 9), (1, 3)]
Output: [(10, 12), (5, 6), (7, 9), (1, 3)]

"""

# traverse and sort

def mergeintervals(arr):
    result = []
    for i in range(len(arr)):
        if len(result) == 0:
            result.append(arr[i])
        for j in range(0,len(result)):
            if arr[i][1] <= result[j][0]:
                result.insert(0,arr[i])
            elif arr[i][0] <= result[j][1] and arr[i][1] >= result[j][1]:
                temp = (result[j][0],arr[i][1])
                result[j] = temp
            elif arr[i][0] >= result[j][1]:
                result.append(arr[i])
    for k in range(0,len(result)-1):
        print(k)
        print(result)
        if result[k][1] >= result[k+1][0]:
            temp = (result[k][0],result[k+1][1])
            result[k] = temp
            result.pop(k+1)
    return result


if __name__ == '__main__':
    print(mergeintervals([(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]))

"""
Time: 40 mins
Unfinish. I pass case 2 but have error in case 1
"""