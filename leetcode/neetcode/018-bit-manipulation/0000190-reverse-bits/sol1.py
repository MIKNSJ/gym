class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0

        for i in range(32):
            result = result << 1
            result = result | (n >> i & 1)
            # if n % 1, then add n = n >> 1 below
        
        return result