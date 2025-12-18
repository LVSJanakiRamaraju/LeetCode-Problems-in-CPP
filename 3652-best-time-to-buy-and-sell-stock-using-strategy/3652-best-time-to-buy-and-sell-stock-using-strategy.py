class Solution:
    def maxProfit(self, prices, strategy, k):
        n = len(prices)
        half = k // 2

        # 1) Base profit
        base = 0
        for i in range(n):
            base += strategy[i] * prices[i]

        best = base

        # 2) Delta for the first window [0 ... k-1]
        delta = 0

        # First half -> force to 0
        for i in range(half):
            delta -= strategy[i] * prices[i]

        # Second half -> force to 1
        for i in range(half, k):
            delta += (1 - strategy[i]) * prices[i]

        best = max(best, base + delta)

        # 3) Slide the window
        for l in range(1, n - k + 1):
            out_first = l - 1              # leaves first half
            move = l + half - 1            # moves second -> first
            enter_second = l + k - 1       # enters second half

            # element leaving first half
            delta += strategy[out_first] * prices[out_first]

            # element switching halves
            delta -= (1 - strategy[move]) * prices[move]
            delta -= strategy[move] * prices[move]

            # new element entering second half
            delta += (1 - strategy[enter_second]) * prices[enter_second]

            best = max(best, base + delta)

        return best