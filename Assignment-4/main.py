from Trie import Trie
"""
Time Complexity: O(L*N) where L is length of longest word and N is # words
Space Complexity: O(L*N) where L is length of longest word and N is # words
leetcode 208
"""
trie = Trie()
def TrieTest():
    # Insert
    words_to_insert = ["apple", "app", "bat", "batman"]
    for word in words_to_insert:
        trie.insert(word)
        print("Inserted: " +word)

    # Check if valid
    words_to_check = ["apple", "app", "bat", "batman", "appl", "batma", "batwoman"]
    for word in words_to_check:
        print(word,trie.isValidWord(word))

    # Remove
    words_to_remove = ["app", "batman"]
    for word in words_to_remove:
        trie.remove(word)
        print("Removed: " +word)

    # Check remove
    for word in words_to_check:
        print(word,trie.isValidWord(word))

"""
DFS + Trie
Assume: I can return result in uppercase
21 mins + GPT debug
Time Complexity: O(M*N + L*W ) where M is #rows, N is #cols,L is length of longest word and W is # words
Space Complexity: O(M*N) where M is #rows and N is #cols
"""
def findWords(board, words):
    trie = Trie()
    for word in words:
        trie.insert(word.upper())

    result = set()
    rows, cols = len(board), len(board[0])

    def dfs(x, y, current_node, path):
        print(f"Visiting: ({x}, {y}), path: {path}")
        if current_node.isEnd:
            print(f"Found a word: {path}")
            result.add(path)

        # 1. check index inside the bound and not visited
        if 0 <= x < rows and 0 <= y < cols and board[x][y] in current_node.children:
            char = board[x][y].upper() # change to upper
            current_node = current_node.children[char]

            # 2. mark as visited
            board[x][y] = "1"

            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
                dfs(x + dx, y + dy, current_node, path + char)

            # Reset current cell
            board[x][y] = char

    for i in range(rows):
        for j in range(cols):
            dfs(i, j, trie.root, "")

    return list(result)


"""
Leetcode 295
heap
Assume: I can import heapq in python
time: 34 mins
Time Complexity: O(logn) n is length of current stream
Space Complexity: O(n)
"""
import heapq
def running_median(stream):
    def addNum(num, maxHeap, minHeap):
        heapq.heappush(maxHeap, -num)
        heapq.heappush(minHeap, -heapq.heappop(maxHeap))
        if len(minHeap) > len(maxHeap):
            heapq.heappush(maxHeap, -heapq.heappop(minHeap))
        return maxHeap, minHeap

    def findMedian(maxHeap, minHeap):
        if len(minHeap) == len(maxHeap):
            return (-maxHeap[0] + minHeap[0]) / 2.0
        return -maxHeap[0]

    maxHeap, minHeap = [], []
    result = []

    for num in stream:
        maxHeap, minHeap = addNum(num, maxHeap, minHeap)
        result.append(findMedian(maxHeap, minHeap))

    return result
"""
Mathematics
40+ mins
Time Complexity: O(n^2)
Space Complexity: O(1)
"""


def catalanNumbers(n):
    if n == 0:
        return [1]

    catalan = [1]
    for i in range(1, n + 1):
        ci = 0
        for j in range(i):
            ci += catalan[j] * catalan[i - j - 1]
        catalan.append(ci)
    return catalan


"""
DP
40+ mins with help from others
Time Complexity: O(n), where n is length of cost
Space Complexity: O(n), where n is length of cost
"""


def minCostClimbingStairs(cost):
    n = len(cost)

    # base case, less than 2
    if n <= 1:
        return 0

    dp = [0] * n
    dp[0], dp[1] = cost[0], cost[1]

    for i in range(2, n):
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])

    return min(dp[-1], dp[-2])

"""
DP
40+ mins
Time Complexity: O(n^2 * m), where n is length of s and m is average length of words in wordDict
Space Complexity: O(n), where n is length of s
"""

def wordBreak(s,wordDict):
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    wordSet = set(wordDict)

    for i in range(1, n + 1):
        for j in range(i):
            dp[j] = True
            if s[j:i] in wordSet:
                dp[i] = True
                break

    return dp[n]


"""
DP
40+ mins
Time Complexity: O(mn), where m is length of rows and n is length of cols
Space Complexity: O(mn), where m is length of rows and n is length of cols
Wrong
"""
def largestSquareOf1s(matrix):
    if not matrix or not matrix[0]:
        return 0
    m, n = len(matrix), len(matrix[0])
    dp = [[0] * n for x in range(m)]
    maxSize = 0

    for i in range( m ):
        for j in range(n):
            # check the bound
            if i == 0 or j == 0:
                dp[i][j] = 1
            # update dp
            dp[i][j] = min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])
    # update maxSize
    return maxSize

"""
DP
23 mins
Time Complexity: O(mn) where m is target sum and n is length of coins
Space Complexity: O(m)
"""
def coinChangeWays(coins, sum):
    dp = [0] * (sum + 1)
    dp[0] = 1

    for coin in coins:
        for j in range(coin, sum + 1):
            dp[j] += dp[j - coin]

    return dp[sum]

"""
deque
40+ mins
Time Complexity: O(1) for addPet and adopt
Space Complexity: O(p), where p is number of animals
Wrong
"""
from collections import deque
class Shelter:
    def __init__(self):
        self.dogs = deque()
        self.cats = deque()

    def addPet(self, name, species, days):
        if species == "dog":
            self.dogs.append((name, days))
        elif species == "cat":
            self.cats.append((name, days))

    def adopt(self, pref_species):
        if pref_species == "dog":
            if self.dogs:
                return self.dogs.popleft()
            else:
                return self.cats.popleft()
        elif pref_species == "cat":
            if self.cats:
                return self.cats.popleft()
            else:
                return self.dogs.popleft()


if __name__ == '__main__':
    # 1
    TrieTest()

    #2
    board = [
        ['A', 'D', 'E'],
        ['R', 'C', 'P'],
        ['L', 'A', 'Y']
    ]
    words = [
        "Ace", "Ape", "Cape", "Clap", "Clay", "Gape", "Grape", "Lace",
        "Lap", "Lay", "Mace", "Map", "May", "Pace", "Pay", "Rap", "Ray",
        "Tap", "Tape", "Trace", "Trap", "Tray", "Yap"
    ]
    print(findWords(board, words))

    # 3
    nums = [1, 11, 4, 15, 12]
    print(running_median(nums))

    # 4
    print(catalanNumbers(1))
    print(catalanNumbers(5))

    #5
    cost = [11, 8, 3, 4, 9, 13, 10]
    print(minCostClimbingStairs(cost))

    #6
    # Wrong
    wordDict = {
        "Elf": True,
        "Go": True,
        "Golf": True,
        "Man": True,
        "Manatee": True,
        "Not": True,
        "Note": True,
        "Pig": True,
        "Quip": True,
        "Tee": True,
        "Teen": True
    }
    print(wordBreak("manatee",wordDict))

    # 7
    matrix = [[0,1,0,1,1],[0,0,1,1,1],[1,1,1,1,1],[1,1,1,1,1],[0,1,1,0,0]]
    # print(largestSquareOf1s(matrix))

    # 8
    coins =  [2, 5, 10]
    sum = 15
    print(coinChangeWays(coins,sum))

    #9
    shelter = Shelter()
    shelter.add_pet( "Sadie", "dog", 4)
    shelter.add_pet( "Woof", "cat", 7)
    shelter.add_pet( "Chirpy", "dog", 2)
    shelter.add_pet( "Lola", "dog", 1)
    print(shelter.adopt_pet("Bob", "dog"))