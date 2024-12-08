class Solution:
    def findMin(self, nums: List[int]) -> int:
        if (len(nums) == 1):
            return nums[0]
        
        left = 0
        right = len(nums) - 1

        if (nums[left] < nums[right]):
            return nums[left]
        
        while left < right:
            leftValue = nums[left]
            rightValue = nums[right]
            midIdx = (left + right) // 2
            midValue = nums[midIdx]

            if midValue > rightValue:
                left = midIdx + 1
            else:
                right = midIdx
               
        leftValue = nums[left]
        return leftValue