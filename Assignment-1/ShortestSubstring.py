# Yuwei Sun UCP
# ShortestSubstring

"""
Given a string and a second string representing required characters, return the length of the shortest substring
containing all the required characters.

Input Strings: "abracadabra", "abc"
Output: 4
(Shortest Substring: "brac")

Input Strings: "zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx" (Fun fact: "Zzyzx" is a town in the Mojave Desert in California!)
Output: 10
(Shortest Substring: "zzxwdcbxyz")

Input Strings: "dog", "god"
Output: 3
(Shortest Substring: "dog")
"""

# sliding window from shorter to longer

def findSS(str,target):
    window = len(target)

    # dict which have all character in target and frequency
    dict_target = {}
    for i in target:
        if i in dict_target:
            dict_target[i] += 1
        else:
            dict_target[i] = 1

    while window <= len(str):
        start_pointer = 0
        while start_pointer + window < len(str):
            dict_temp = {}
            for i in str[start_pointer:start_pointer+window]:
                if i in dict_target: # compare with target
                    if i in dict_temp:
                        dict_temp[i] += 1
                    else:
                        dict_temp[i] = 1
            if dict_temp == dict_target:
                return window
            else:
             start_pointer += 1
        window += 1
    return 0


if __name__ == '__main__':
    print(findSS("dog","god"))


"""
Time: 40 mins
Unfinish, and return None

Why: 1. spend too much time on thinking a good solution rather than a "possible" solution.
    2. forget some basic syntax of python dict, spend time on try and test dict code
"""