class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        S = ""
        for i in digits:
            S+=str(i)
        N = int(S)
        N += 1
        S = str(N)
        l = []
        L = list(S)
        for i in L:
            l.append(int(i))
        return l
        
        