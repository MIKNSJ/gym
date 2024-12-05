class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
    
        if len(s) == 1:
            return 1

        left = 0
        right = 1
        length = 1
        maxLength = 1
        visited = set()
        visited.add(s[left])

        while right < len(s):
            if s[right] in visited:
                visited.clear()
                left+=1
                right = left
                visited.add(s[left])
                length = 1
            else:
                length+=1
                visited.add(s[right])

                if maxLength < length:
                    maxLength = length

            right+=1
                
        return maxLength