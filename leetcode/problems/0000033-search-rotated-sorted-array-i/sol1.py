class Solution:
    def findMinIdx(self, nums: list[int]) -> int:
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

        return left

    def search(self, nums: List[int], target: int) -> int:
        if (len(nums) == 1 and nums[0] == target):
            return 0

        if (len(nums) == 1 and nums[0] != target):
            return -1

        minIdx = self.findMinIdx(nums)

        if (minIdx == 0):
            left = nums[0]
            right = len(nums) - 1
        elif target >= nums[0] and target <= nums[minIdx - 1]:
            left = 0
            right = minIdx - 1
        else: # target >= nums[minIdx] and target <= nums[len(nums) - 1]
            left = minIdx
            right = len(nums) - 1

        while left <= right:
            leftValue = nums[left]
            rightValue = nums[right]
            midIdx = (left + right) // 2
            midValue = nums[midIdx]
        
            if target < midValue:
                right = midIdx - 1
            elif target > midValue:
                left = midIdx + 1
            else:
                return midIdx

        return -1