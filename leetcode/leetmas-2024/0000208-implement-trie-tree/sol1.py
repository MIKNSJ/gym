class Trie:

    def __init__(self):
        self.val = ""
        self.next = dict()
        self.isValidWord = True

    def insert(self, word: str) -> None:
        if word == "" or word == None:
            return

        currCharNode = self
        for i in range(len(word)):
            if word[i] not in currCharNode.next:
                newNode = Trie()
                newNode.val = word[i]
                newNode.next = dict()
                newNode.isValidWord = False
                currCharNode.next[word[i]] = newNode
            
            currCharNode = currCharNode.next[word[i]]
        
        if not currCharNode.isValidWord:
            currCharNode.isValidWord = True

        return


    def search(self, word: str) -> bool:
        if word == "" or word == None:
            return True

        currCharNode = self
        currWord = ""
        idx = 0
        while currWord != word:
            if word[idx] in currCharNode.next:
                currWord += word[idx]
                currCharNode = currCharNode.next[word[idx]]
            else:
                return False
            idx+=1
        
        if not currCharNode.isValidWord:
            return False
    
        return True
        

    def startsWith(self, prefix: str) -> bool:
        if prefix == "" or prefix == None:
            return True

        currCharNode = self
        currPrefix = ""
        idx = 0
        while currPrefix != prefix:
            if prefix[idx] in currCharNode.next:
                currPrefix += prefix[idx]
                currCharNode = currCharNode.next[prefix[idx]]
            else:
                return False
            idx+=1
    
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)