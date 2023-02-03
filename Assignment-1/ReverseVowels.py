# Yuwei Sun UCP
# ReverseVowels

"""
Given a string, reverse the order of the vowels in the string.

Input String: "Uber Career Prep"
Modified String: "eber Ceraer PrUp"

Input String: "xyz"
Modified String: "xyz"

Input String: "flamingo"
Modified String: "flominga"

"""

# double pointer, and assume I can modify the original data

def reversevowels(str):
    vowels = {"a","e","i","o","u"}
    left = 0
    str_list = list( str )
    right = len(str_list) - 1
    result = ""
    while left < right:
        if str_list[left].lower() not in vowels:
            left += 1
        if str_list[right].lower() not in vowels:
            right -= 1
        if str_list[left].lower() in vowels and str_list[right].lower() in vowels:
            #str[left],str[right] = str[right],str[left]
            str_list[left],str_list[right] = str_list[right],str_list[left]
            left += 1
            right -= 1

    for i in str_list:
        result += i

    return result



if __name__ == '__main__':
    print(reversevowels("flamingo"))

"""
Time: 17 mins
bug1: vowels = {"a","e","i","o","u"} rather than vowels = set{"a","e","i","o","u"}
bug2: 'str' object does not support item assignment

Time-complexity: O(N), where N is length of string
Space-complexity: O(N+5), where N is length of string
"""
