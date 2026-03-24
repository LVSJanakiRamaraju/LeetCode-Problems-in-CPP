class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        long long start = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = start % 12345;
                start = (start * grid[i][j]) % 12345;
            }
        }
        long long end = 1;
        for(int i = n-1; i>-1; i--){
            for(int j=m-1; j>-1; j--){
                ans[i][j] = (ans[i][j] * end) % 12345;
                end = (end * grid[i][j]) % 12345;
            }
        }

        return ans;
    }
};