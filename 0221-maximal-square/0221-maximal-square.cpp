class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea =0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxVal = 0;
        for(int i=0; i<n; i++){
            dp[i][0] = matrix[i][0] - '0';
            maxVal = max(maxVal, dp[i][0]);
        }
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j] - '0';
            maxVal = max(maxVal, dp[0][j]);
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                maxVal = max(maxVal, dp[i][j]);
                if(matrix[i][j] == '1'){
                    int minVal = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+ 1;
                    dp[i][j] = minVal;
                    maxVal = max(maxVal, dp[i][j]);
                }

                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return maxVal* maxVal;
    }
};