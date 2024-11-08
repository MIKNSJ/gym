class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        visited_nums = set([])
        left = 0
        right = len(nums) - 1
        nums = sorted(nums)
        distance = 99999999999999
        shortest_distance = 99999999999999
        closest_sum = nums[0] + nums[1] + nums[2]

        for i in range(len(nums)):
            if nums[i] not in visited_nums:
                left = i + 1
                while left <= right:
                    sum = nums[i] + nums[left] + nums[right]

                    if sum == target and i != left and i != right and left != right:
                        return sum

                    elif sum > target and nums[left] <= nums[right]:
                        distance = abs(sum - target)

                        if shortest_distance > distance and i != left and i != right and left != right:
                            shortest_distance = distance
                            closest_sum = sum

                        right-=1

                    elif sum < target and nums[left] <= nums[right]:
                        distance = abs(sum - target)

                        if shortest_distance > distance and i != left and i != right and left != right:
                            shortest_distance = distance
                            closest_sum = sum

                        left+=1

                    else: # sum = 0, but either i == left or i == right
                        left+=1 # default assignment, could either be right-=1

            left = i + 1
            right = len(nums) - 1
            visited_nums.add(nums[i])

        return closest_sum