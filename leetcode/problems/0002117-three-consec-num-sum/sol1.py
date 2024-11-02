class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        new_num = num - 3

        if (new_num % 3 == 0):
            x = new_num // 3
        else:
            return []
        
        return [x, x+1, x+2]