# sum approach

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total_sum = 0
        sum = 0

        for i in range(len(nums) + 1):
            total_sum+=i
        
        for j in range(len(nums)):
            sum+=nums[j]

        return total_sum - sum