class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        result = []
        left = 0
        right = len(numbers) - 1

        while left <= right:
            if numbers[left] + numbers[right] == target:
                result.append(left + 1)
                result.append(right + 1)
                break

            elif numbers[left] + numbers[right] > target:
                right-=1

            else:
                left+=1

        return result