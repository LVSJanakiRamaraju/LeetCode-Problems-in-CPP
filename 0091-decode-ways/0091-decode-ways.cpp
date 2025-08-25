class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int result =0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++){
            int first = s[i-1] - '0';
            int second = stoi(s.substr(i-2, 2));
            if(first<=9 and first>0)    dp[i] += dp[i-1];
            if(second<27 and second>9)  dp[i] += dp[i-2];
        }
        return dp[n];
    }
};