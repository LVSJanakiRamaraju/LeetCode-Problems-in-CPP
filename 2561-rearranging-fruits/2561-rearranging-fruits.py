class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        n = len(basket1)
        count1 = Counter(basket1)
        count2 = Counter(basket2)
        min_val = min(basket1 + basket2)

        swap1 = []
        for item in count1:
            c1 = count1[item]
            c2 = count2.get(item, 0)
            if (c1 + c2) % 2 != 0:
                return -1
            if c1 > c2:
                swap1.extend([item] * ((c1 - c2) // 2))

        swap2 = []
        for item in count2:
            c2 = count2[item]
            c1 = count1.get(item, 0)
            if (c1 + c2) % 2 != 0:
                return -1
            if c2 > c1:
                swap2.extend([item] * ((c2 - c1) // 2))

        swap1.sort()
        swap2.sort(reverse=True)

        res = 0
        for x, y in zip(swap1, swap2):
            res += min(2 * min_val, min(x, y))

        return res