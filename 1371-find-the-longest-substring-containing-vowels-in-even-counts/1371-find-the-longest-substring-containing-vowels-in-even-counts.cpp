class Solution {
public:
    int findTheLongestSubstring(string s) {
        int sum=0, maxSum = 0;
        int n = s.size();
        int a = 1, e = 2, i= 4, o = 8, u = 16;
        vector<int> freq(26, 0);
        freq['a' - 'a'] = 1;
        freq['e' - 'a'] = 2;
        freq['i' - 'a'] = 4;
        freq['o' - 'a'] = 8;
        freq['u' - 'a'] = 16;

        vector<int> dp(32, -1);
        for(int i=0; i<n; i++){
            sum ^= freq[s[i] - 'a'];

            if(dp[sum] == -1 and sum != 0)   dp[sum] = i;
            maxSum = max(maxSum, i-dp[sum]);
        }
        return maxSum;
    }
};