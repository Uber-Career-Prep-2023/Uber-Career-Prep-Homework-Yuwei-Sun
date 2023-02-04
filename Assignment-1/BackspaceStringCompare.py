# Yuwei Sun UCP
# BackspaceStringCompare

"""
Given two strings representing series of keystrokes, determine whether the resulting text is the same. Backspaces are
represented by the '#' character so "x#" results in the empty string ("").

Input Strings: "abcde", "abcde"
Output: True

Input Strings: "Uber Career Prep", "u#Uber Careee#r Prep"
Output: True

Input Strings: "abcdef###xyz", "abcw#xyz"
Output: True

Input Strings: "abcdef###xyz", "abcdefxyz###"
Output: False
"""

# listlize string, and pop()
# assume case sensitive

def Compare(str1,str2):
    lst_str1 = []
    lst_str2 = []
    for i in str1:
        if i == "#":
            lst_str1.pop()
        else:
            lst_str1.append(i)
    for i in str2:
        if i == "#":
            lst_str2.pop()
        else:
            lst_str2.append(i)
    if lst_str1 == lst_str2:
        return True
    else:
        return False

if __name__ == '__main__':
    print(Compare("abcdef###xyz", "abcdefxyz###"))


"""
Time: 6 mins

time-complexity: O(M+N+min(M+N)), where M and N is length of input string
space-complexity: O(M+N), where M and N is length of input string
"""