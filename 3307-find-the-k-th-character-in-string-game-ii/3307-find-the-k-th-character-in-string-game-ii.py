class Solution(object):
    def kthCharacter(self, k, operations):
        """
        :type k: int
        :type operations: List[int]
        :rtype: str
        """
        result = 0
        n = len(operations)
        l = pow(2, n-1)
        for i in range(n-1, -1, -1):
            if k > l:
                k -= l
                if operations[i]:
                    result += 1
            l //= 2
        return chr(97 + result%26)
        