class Solution {
public:
    bool checkDivisibility(int n) {
        int org = n;
        int digitSum = 0, digitPro =1;
        while(n){
            int digit = n % 10;
            digitSum += digit;
            digitPro *= digit;
            n /= 10;
        }

        int total = digitSum + digitPro;
        return org%total == 0;
    }
};