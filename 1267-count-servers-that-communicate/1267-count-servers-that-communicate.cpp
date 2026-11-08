class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result =0, n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                result += grid[i][j];
            }
        }
        for(int i=0; i<n; i++){
            int count =0, last = 0, x=0;
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    count++;
                    last = j;
                }
            }
            if(count == 1){
                for(int k =0; k<n; k++){
                    if(grid[k][last])  x++;
                }
                if(x == 1)  result -=1;
            }
        }

        return result;
    }
};