class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+2, LLONG_MAX);
        dp[0] = 0;
        costs.insert(costs.begin(), 0);
        for(int i=0; i<=n; i++){
            if(dp[i] == LLONG_MAX)   continue;
            for(int jump =1; jump <= 3; jump++){
                int prev =i+jump;
                if(prev <= n)  dp[prev] = min(dp[prev], dp[i] + costs[prev] + (1LL * jump * jump));
            }
        }
        return (int)dp[n];
    }
};