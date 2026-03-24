class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<long long>> maxValue(n, vector<long long>(m)), minValue(n, vector<long long>(m));
        maxValue[0][0] = minValue[0][0] = grid[0][0];

        for(int i=1; i<n; i++)  maxValue[i][0] = minValue[i][0] = maxValue[i-1][0] * grid[i][0];
        for(int i=1; i<m; i++)  maxValue[0][i] = minValue[0][i] = maxValue[0][i-1] * grid[0][i];


        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j] >= 0){
                    maxValue[i][j] = max(maxValue[i][j-1], maxValue[i-1][j]) * grid[i][j];
                    minValue[i][j] = min(minValue[i][j-1], minValue[i-1][j]) * grid[i][j];
                }
                else{
                    maxValue[i][j] = min(minValue[i][j-1], minValue[i-1][j]) * grid[i][j];
                    minValue[i][j] = max(maxValue[i][j-1], maxValue[i-1][j]) * grid[i][j];
                }
            }
        }

        if(maxValue[n-1][m-1] < 0)  return -1;
        return maxValue[n-1][m-1] % mod;


    }
};