class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0

        if len(height) == 1:
            return 0

        left = 0
        right = len(height) - 1
        curr_height = 0
        area = 0
        maxArea = 0

        while left <= right:
            if (height[left] <= height[right]):
                curr_height = height[left]
            else:
                curr_height = height[right]

            area = (right - left) * curr_height

            if (maxArea < area):
                maxArea = area

            curr_height = 0
            area = 0

            if (height[left] <= height[right]):
                left+=1
            else:
                right-=1

        return maxArea