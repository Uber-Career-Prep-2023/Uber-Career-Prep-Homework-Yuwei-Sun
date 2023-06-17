from collections import deque # for dfs and topological sort

'''
DFS
Time use: 38
time-complexity: O(N) where NM is length N is high of matrix and M is high of matrix
space-complexity: O(1)
'''
def NumberOfIslands_helper_dfs(matrix,i,j):
    # check index in the matrix and it is land
    if i >= 0 and i < len(matrix) and j >= 0 and j < len(matrix) and matrix[i][j] == 1:
        matrix[i][j] = 0 # mark it as visited
        # left, right,up,down
        NumberOfIslands_helper_dfs(matrix,i-1,j)
        NumberOfIslands_helper_dfs( matrix, i +1, j )
        NumberOfIslands_helper_dfs( matrix, i, j+1 )
        NumberOfIslands_helper_dfs( matrix, i , j-1 )


def NumberOfIslands(matrix):
    counter = 0
    # traverse matrix to find the land, and dfs to find all connected land.
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 1:
                NumberOfIslands_helper_dfs(matrix,i,j)
                counter += 1
    return counter

"""
string slice
time: 9 mins
time-complexity: O(N) where N is length of num
space-complexity: O(N)
"""
def FirstKBinaryNumbers(num):
    result = []
    for i in range(num):
        result.append(str(bin(i)[2:]))
    return result

"""
DFS
time: 40 + 13
time-complexity: O(V + E) where V is number of towns and E is number of roads.
space-complexity: O(V + E) where V is number of towns and E is number of roads.
Debug: In networks, road should be store as key->list[value] rather than key->value
Real Bug: result wrong!
"""
def RoadNetworks_helper_dfs(visited,j,networks):
    visited[j] = True # visited
    for k in networks[j]:
        if visited[k] == False:
            RoadNetworks_helper_dfs(visited,k,networks)

# towns contain all towns. roads contain all pairs of town which represent road.
def RoadNetworks(towns,roads):
    networks = {}
    visited = {}
    counter = 0

    # change towns,roads into dict of lists
    for i in towns:
        networks[i] = [] # use list as roads are not one-to-one
        visited[i] = False
    for pair in roads:
        if pair in towns:
            networks[pair[0]].append(pair[1])
            networks[pair[1]].append( pair[0] )

    # search
    for j in towns:
        if visited[j] == False: # not visited
            RoadNetworks_helper_dfs(visited,j,networks)
            counter += 1
    return counter

"""
string operation, join
time: 11 mins
time-complexity: O(N) where N is length of str
space-complexity: O(N) where N is length of str
It is impossible to get O(1) space complexity as str in python is immutable ?
"""
# return the string with the order of the space-separated words reversed
def ReverseWords(str):
    words = str.split(' ')
    words.reverse()
    result = ' '.join(words)
    return result


"""
BFS
40 + 17, couldn't find bug
time-complexity: O(V+E) where V is number of Node(A,b,C,etc) and E is number of edges.
space-complexity: O(V+E) where V is number of Node(A,b,C,etc) and E is number of edges.
"""

def AlternatingPath(graph,origin, destination):
    roads = {} # store node in graph
    for u, v, color in graph:
        if u not in roads:
            roads[u] = {'red': [], 'blue': []}
        if color == "blue":
            roads[u]['blue'].append( v )
        else:
            roads[u]['red'].append( v )
    #print(roads)
    visited = {}
    for i in roads.keys():
        if i not in visited:
            visited[i] = {'red': False, 'blue': False}

    queue = deque([(origin,"red"),(origin,"blue")])

    counter = 0
    while queue:
        node,color = queue.popleft()
        if node == destination:
            return counter
        if color == "blue":
            color_next = "red"
        else:
            color_next = "blue"
        for j in roads[node][color_next]:
            if visited[j][color_next] == False:
                queue.append((j,color_next))
                counter += 1
                visited[j][color_next] = True
        return -1

"""
Divide-and-Conquer
time: 23 mins
time-complexity: O(N*K)，where N is length of (list1+list2) and K is the number of merges but N is increasing
space-complexity: O(N) where N is length of result
"""
def MergeTwoSortedArrays(list1,list2):
    p1 = 0
    p2 = 0
    result = []
    while p1 < len(list1) and p2 < len(list2):
        if list1[p1] <= list2[p2]:
            result.append(list1[p1])
            p1 += 1
        else:
            result.append(list2[p2])
            p2 += 1
    while p1 < len(list1):
        result.append(list1[p1])
        p1 += 1
    while p2 < len(list2):
        result.append(list2[p2])
        p2 += 1
    return result

def MergeKSortedArrays(num,list):
    result = []
    p = num - 1
    while p >= 0:
        merged_list = MergeTwoSortedArrays(result,list[p])
        result = merged_list
        p -=1
    return result

"""
topological sort
time: 40 + 3
time-complexity: O(V) where V is length of course_list
space-complexity: O(V+E) where V is length of course_list and E is length of course_map

Assume: Only one prerequisite requirement per course (for: adjList[prereq[0]].append(cur))
"""
def PrerequisiteCourses(course_list, course_map):
    adjList = {i : [] for i in course_list}
    inDegreeMap = {j:0 for j in course_list}
    result = []

    for cur,prereq in course_map.items():
        adjList[prereq[0]].append(cur)
        inDegreeMap[cur] += 1 # we need to finish one more prereq to take this courses

    # Add the courses with 0 inDegree into queue
    queue = deque([course for course in inDegreeMap if inDegreeMap[course] == 0])

    while queue:
        course = queue.popleft()
        result.append(course)

        for i in adjList[course]:
            inDegreeMap[i] -= 1
            if inDegreeMap[i] == 0 and i not in queue:
                queue.append(i)

    return result

"""
DFS maybe?
time: 40, I don't know how to include the time variable and how to recursively


"""
def VacationDestinations_helper_dfs(visited,j,networks,time,counter,k):
    visited[j] = True # visited
    for m in networks[j]:
        if visited[m] == False and time < k:
            counter += 1
            VacationDestinations_helper_dfs(visited,m,networks,time,counter,k)

# towns contain all towns. roads contain all pairs of town which represent road.
def VacationDestinations(k,roads):
    networks = {}
    visited = {}
    counter = 0

    # change roads into dict of lists
    for city1, city2, time in roads:
        if city1 not in networks.keys():
            networks[city1] = []
        if city2 not in networks.keys():
            networks[city2] = []
        networks[city1].append((city2,time))
        networks[city2].append((city1,time))
        visited[city1] = False
        visited[city2] = False

    # search
    #  DFS
    return counter


if __name__ == '__main__':
    matrix = [[1,0,1,1,1],[1,1,0,1,1],[0,1,0,0,0],[0,0,0,1,0],[0,0,0,0,0]]
    print("Q4:")
    print(NumberOfIslands(matrix))

    print("Q5:")
    print(FirstKBinaryNumbers(5))

    towns = ["Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy",
            "Copper Center", "Healy"]
    roads = [("Anchorage", "Homer"), ("Glacier Bay", "Gustavus"), ("Copper Center", "McCarthy"), ("Anchorage", "Copper Center"),
     ("Copper Center", "Fairbanks"), ("Healy", "Fairbanks"), ("Healy", "Anchorage")]
    print("Q6:")
    print(RoadNetworks(towns,roads))

    str = "Emma lives in Brooklyn, New York."
    print("Q7:")
    print(ReverseWords(str))

    graph = [("A", "B", "blue"), ("A", "C", "red"), ("B", "D", "blue"), ("B", "E", "blue"), ("C", "B", "red"),
             ("D", "C", "blue"), ("A", "D", "red"), ("D", "E", "red"), ("E", "C", "red")]
    print("Q8:")
    print(AlternatingPath(graph,"A","E"))

    list = [[1, 4, 7, 9], [2, 6, 7, 10, 11, 13, 15], [3, 8, 12, 13, 16]]
    print("Q9:")
    print(MergeKSortedArrays(3,list))

    course = ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"]
    map = { "Data Structures": ["Intro to Programming"], "Advanced Algorithms": ["Data Structures"],
            "Operating Systems": ["Advanced Algorithms"], "Databases": ["Advanced Algorithms"] }
    print("Q10:")
    print(PrerequisiteCourses(course,map))