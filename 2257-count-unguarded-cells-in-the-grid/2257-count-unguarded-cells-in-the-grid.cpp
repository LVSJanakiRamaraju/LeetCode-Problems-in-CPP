class Solution {
public:

    void cell(int r, int c, int& m, int& n, vector<vector<int>>& grid){
        for(int i = r+1; i<m; i++){
            if(grid[i][c] == 1 || grid[i][c] == 2)  break;
            grid[i][c] = 0;
        }
        for(int i = r-1; i>=0; i--){
            if(grid[i][c] == 1 || grid[i][c] == 2)  break;
            grid[i][c] = 0;
        }
        for(int i = c+1; i<n; i++){
            if(grid[r][i] == 1 || grid[r][i] == 2)  break;
            grid[r][i] = 0;
        }
        for(int i = c-1; i>=0; i--){
            if(grid[r][i] == 1 || grid[r][i] == 2)  break;
            grid[r][i] = 0;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        for(auto guard : guards){
            grid[guard[0]][guard[1]] = 1;
        }
        for(auto wall : walls){
            grid[wall[0]][wall[1]] = 2;
        }
        int ans = 0;
        for(auto guard : guards){
            cell(guard[0], guard[1], m, n, grid);
        }

        for(auto row : grid){
            for(auto col : row){
                if(col == -1)   ans++;
            }
        }

        return ans;
    }
};