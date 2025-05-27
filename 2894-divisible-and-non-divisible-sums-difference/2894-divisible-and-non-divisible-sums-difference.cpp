class Solution {
    public:
     int differenceOfSums(int n, int m) {
        int sum1 = n*(n+1)/2;
        int sum2 = (n/m)*m;
        int terms = ((sum2-m)/m) + 1;
        sum2 = (terms*(sum2 + m))/2;
        return sum1 - sum2 - sum2;
    }
};