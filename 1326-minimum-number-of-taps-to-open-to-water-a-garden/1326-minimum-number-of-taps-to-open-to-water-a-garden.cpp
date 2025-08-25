class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<long long> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<=n; i++){
            for(int j = max(i-ranges[i]+1, 0); j<= min(i+ranges[i], n); j++){
                dp[j] = min(dp[j], dp[max(0, i - ranges[i])] + 1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];


    }
};