class WordDictionary:

    def __init__(self):
        self.val = ""
        self.next = dict()
        self.isValidWord = True


    def addWord(self, word: str) -> None:
        if word == "" or word == None:
            return

        currCharNode = self
        for i in range(len(word)):
            if word[i] not in currCharNode.next:
                newNode = WordDictionary()
                newNode.val = word[i]
                newNode.next = dict()
                newNode.isValidWord = False
                currCharNode.next[word[i]] = newNode
            
            currCharNode = currCharNode.next[word[i]]
        
        if not currCharNode.isValidWord:
            currCharNode.isValidWord = True
        
        return


    def search(self, word: str) -> bool:
        #if word == "" or word == None:
            #return True

        currCharNode = self
        currWord = ""
        idx = 0
        while currWord != word:
            if word[idx] in currCharNode.next:
                currWord += word[idx]
                currCharNode = currCharNode.next[word[idx]]
            elif word[idx] == ".":
                for currCharNode in currCharNode.next.values():
                    if currCharNode.search(word[idx + 1:]):
                        return True
                return False
            else:
                return False
            idx+=1
        
        if not currCharNode.isValidWord:
            return False
        
        return True


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)