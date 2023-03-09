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

# use hash table and tuple
def mergeintervals_hash(arr):
    the_dict = {}
    result = []
    for i in arr:
        if i[0] in the_dict or i[1] in the_dict:
            if i[0] in the_dict and i[1] in the_dict and the_dict[i[0]] == the_dict[i[1]]:
                continue # left and right are already stored
            elif i[0] not in the_dict and i[1] in the_dict:
                temp = the_dict[i[1]]
                del the_dict[i[1]]
                the_dict[i[0]] = (i[0],temp[1]) # combine the interval
            elif i[0] in the_dict and i[1] not in the_dict:
                the_key = the_dict[i[0]]
                temp = the_dict[the_key]
                del the_dict[the_key]
                the_dict[the_key] = (temp[0],i[1])
        elif i[0] not in the_dict:
            the_dict[i[0]] = i # store the "length"
            for j in range(i[0]+1,i[1]+1,1):
                the_dict[j] = i[0] # key is the middle value(5,6,7,8) and value is i[0]
    for i in the_dict:
        if type(the_dict[i]) == tuple:
            result.append(the_dict[i])
    return result

if __name__ == '__main__':
    print(mergeintervals_hash([(5, 8), (6, 10), (2, 4), (3, 6)]))

"""
Time: 40 mins
Unfinish. I pass case 2 but have error in case 1
"""