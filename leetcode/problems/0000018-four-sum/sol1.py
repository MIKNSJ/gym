class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        values  = []
        set_result = set([])
        visited_nums = set([])
        left = 0
        right = len(nums) - 1
        nums = sorted(nums)

        for i in range(len(nums)):
            if nums[i] not in visited_nums:
                for j in range(i + 1, len(nums)):
                    left = j + 1

                    while left <= right:
                        sum = nums[i] + nums[j] + nums[left] + nums[right]
                        if sum == target and i != left and i != right and left != right and j != left and j != right and i != j:
                            values.append(nums[i])
                            values.append(nums[j])
                            values.append(nums[left])
                            values.append(nums[right])

                            if tuple(values) not in set_result:
                                set_result.add(tuple(values.copy())) 
                                result.append(values.copy())

                            values.clear()
                            left+=1

                        elif sum > target:
                            right-=1

                        elif sum < target:
                            left+=1

                        else: # sum = 0, but either i/j == left or i/j == right or i == j
                            left+=1 # default assignment, could either be right-=1
                    
                    left = j + 1
                    right = len(nums) - 1

                left = i + 1
                right = len(nums) - 1
                visited_nums.add(nums[i])

        return result