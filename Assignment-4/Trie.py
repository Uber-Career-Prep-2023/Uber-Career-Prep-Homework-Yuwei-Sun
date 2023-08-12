class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for i in word:
            if i not in cur.children:
                cur.children[i] = TrieNode()
            cur = cur.children[i]
        cur.isEnd = True

    def isValidWord(self, word: str) -> bool:
        cur = self.root
        for i in word:
            if i not in cur.children:
                return False
            cur = cur.children[i]
        return cur.isEnd

    def remove(self, word: str) -> None:
        def removeHelper(node, word, index):
            if index == len(word):
                if node.isEnd:
                    node.isEnd = False
                    return not bool(node.children)
                return False

            ch = word[index]
            if ch in node.children and removeHelper(node.children[ch], word, index+1):
                del node.children[ch]
                return not node.isEnd and not bool( node.children )
            return False

        removeHelper(self.root, word, 0)

    def search_prefix(self, prefix: str) -> TrieNode:
        cur = self.root
        for i in prefix:
            if i not in cur.children:
                return None
            cur = cur.children[i]
        return cur
