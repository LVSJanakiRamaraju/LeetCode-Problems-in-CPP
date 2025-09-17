class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];

        int ans  =0;
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k= j+1; k<m; k++){
                    for(int x =-1; x<=1; x++){
                        for(int y=-1; y<=1; y++){
                            int nx = j +x, ny = k + y;
                            if(nx>=0 && nx < m && ny >=0 && ny < m){
                                if(dp[i-1][nx][ny] != -1){
                                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][nx][ny] + grid[i][j] + (j != k ? grid[i][k] : 0));
                                }
                            }
                        }
                    }

                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
        return ans;
    }
};