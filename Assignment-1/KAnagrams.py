# Yuwei Sun UCP
# KAnagrams

"""
Two strings are considered to be “k-anagrams” if they can be made into anagrams by changing at most k characters in one
of the strings. Given two strings and an integer k, determine if they are k-anagrams.

Input Strings: "apple", "peach"
Input k: 1
Output: False

Input Strings: "apple", "peach"
Input k: 2
Output: True

Input Strings: "cat", "dog"
Input k: 3
Output: True

Input Strings: "debit curd", "bad credit"
Input k: 1
Output: True

Input Strings: "baseball", "basketball"
Input k: 2
Output: False

"""

# map
# edge case, different size

def KAnagrams(str1,str2,k):
    str_dict = {}
    diff = 0
    if len(str1) is not len(str2):
        return False
    for i in str1:
        if i not in str_dict:
            str_dict[i] = 1
        elif i in str_dict:
            str_dict[i] += 1
    for j in str2:
        if j in str_dict:
            str_dict[j] -= 1
    for n in str_dict.values():
        diff += n
    return diff <= k


if __name__ == '__main__':
    print(KAnagrams("baseball", "basketball",2))

"""
Time: 11

time-complexity: O(N), where N is size of str
space-complexity: O(N), where N is size of str
"""