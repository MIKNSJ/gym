class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0 or len(prices) == 1:
            return 0

        left = 0
        right = 1
        profit = 0
        maxProfit = 0

        while right < len(prices):
            if prices[left] > prices[right]:
                left = right
                profit = 0
            else:
                profit = prices[right] - prices[left]

                if maxProfit < profit:
                    maxProfit = profit

            right+=1

        return maxProfit