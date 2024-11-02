class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        if len(nums) == 1:
            return 1

        nums_set = set([])
        visited_nums = set([])

        for i in range(len(nums)):
            nums_set.add(nums[i])

        curr_seq = 0
        long_seq = 0
        for num in nums_set:
            if num - 1 not in nums_set and num not in visited_nums:
                curr_num = num
                visited_nums.add(curr_num)

                while True:
                    if curr_num + 1 in nums_set:
                        curr_num+=1
                        visited_nums.add(curr_num)
                        curr_seq+=1
                    else:
                        visited_nums.add(curr_num)
                        curr_seq+=1
                        break
            else:
                visited_nums.add(num)

            if long_seq < curr_seq:
                long_seq = curr_seq

            curr_seq = 0

        return long_seq