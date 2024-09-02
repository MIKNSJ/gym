# 1 September 2024

import math

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        
        while n > 0:
            n = n / 2
            remainder = n - math.floor(n)

            if remainder != 0:
                count+=1;
            
            n = math.floor(n)
        
        return count