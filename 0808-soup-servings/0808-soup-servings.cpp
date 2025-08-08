class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;

        int N = (n + 24) / 25; 
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));

        dp[0][0] = 0.5; 
        for (int j = 1; j <= N; ++j) dp[0][j] = 1.0; 
        for (int i = 1; i <= N; ++i) dp[i][0] = 0.0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = 0.25 * (
                    dp[max(0, i - 4)][j] +
                    dp[max(0, i - 3)][max(0, j - 1)] +
                    dp[max(0, i - 2)][max(0, j - 2)] +
                    dp[max(0, i - 1)][max(0, j - 3)]
                );
            }
        }

        return dp[N][N];
    }
};