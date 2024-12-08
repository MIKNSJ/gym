# hashset approach

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        visited = {}

        for i in range(len(nums)):
            if nums[i] not in visited:
                visited[nums[i]] = 1
            else:
                visited[nums[i]]+=1
        
        for key in visited:
            if visited[key] == 1:
                return key