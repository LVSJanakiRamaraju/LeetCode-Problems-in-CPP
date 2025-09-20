class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp = {1, 1, 2, 0, 0, 2, 2, 0, 1, 2};
        int result =0;
        for(int i=1; i<=n; i++){
            int x = i;
            int ans = 1;
            while(x){
                ans *= dp[x%10];
                x /= 10;
            }
            if(ans >= 2)    result++;
        }
        return result;
    }
};