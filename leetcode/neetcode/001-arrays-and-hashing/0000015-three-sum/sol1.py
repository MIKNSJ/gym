class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        values  = []
        set_result = set([])
        visited_nums = set([])
        left = 0
        right = len(nums) - 1
        nums = sorted(nums)

        for i in range(len(nums)):
            if nums[i] not in visited_nums:
                while left <= right:
                    if nums[i] + nums[left] + nums[right] == 0 and i != left and i != right and left != right:
                        values.append(nums[i])
                        values.append(nums[left])
                        values.append(nums[right])

                        if tuple(values) not in set_result:
                            set_result.add(tuple(values.copy())) 
                            result.append(values.copy())

                        values.clear()
                        left+=1

                    elif nums[i] + nums[left] + nums[right] > 0 and nums[left] <= nums[right]:
                        right-=1

                    elif nums[i] + nums[left] + nums[right] < 0 and nums[left] <= nums[right]:
                        left+=1

                    else: # sum = 0, but either i == left or i == right
                        left+=1 # default assignment, could either be right-=1

            left = i + 1
            right = len(nums) - 1
            visited_nums.add(nums[i])

        return result