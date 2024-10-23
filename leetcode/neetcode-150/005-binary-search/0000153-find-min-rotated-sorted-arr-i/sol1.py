class Solution:
    def findMin(self, nums: List[int]) -> int:
        if (len(nums) == 1):
            return nums[0]

        start = 0
        end = len(nums) - 1

        while True:
            startValue = nums[start]
            endValue = nums[end]
            midIdx = (start + end) // 2
            midValue = nums[midIdx]
            
            if (midIdx - 1 < 0):
                leftIdx = len(nums) - 1
            else:
                leftIdx = midIdx - 1
            
            if (midIdx + 1 >= len(nums)):
                rightIdx = 0
            else:
                rightIdx = midIdx + 1

            if midValue <= nums[leftIdx] and midValue <= nums[rightIdx]:
                return midValue

            if startValue > midValue:
                end = midIdx - 1
            elif midValue > endValue:
                start = midIdx + 1
            else:
                return startValue
                   
        return None