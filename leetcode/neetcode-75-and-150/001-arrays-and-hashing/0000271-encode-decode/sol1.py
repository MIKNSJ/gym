class Solution:
    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""

        encodedStrings = ""

        for i in range(len(strs)):
            encodedStrings = encodedStrings + "#" + str(len(strs[i])) + "#"
            encodedStrings+=strs[i]

        return encodedStrings

    def decode(self, s: str) -> List[str]:
        if len(s) == 0:
            return []

        decodedStrings = []
        key = ""
        strTextLength = ""
        word = ""
        idx = 0

        while idx < len(s):
            if key.startswith("#") and key.endswith("#") and key.count("#") == 2 and len(key) > 2:
                print(s)
                for j in range(len(key)):
                    if (key[j] != "#"):
                        strTextLength+=key[j]

                strLength = int(strTextLength)

                endIdx = idx + strLength
                while idx < endIdx:
                    word+=s[idx]
                    idx+=1

                decodedStrings.append(word)

                strTextLength = ""
                word = ""
                key = ""

            if (idx < len(s)):
                key+=s[idx]

            idx+=1
        
        if len(decodedStrings) == 0:
            decodedStrings.append("")

        return decodedStrings