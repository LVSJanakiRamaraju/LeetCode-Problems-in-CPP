class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> a(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
           p[i][0] = true;
           a[i][m-1] = true; 
        }

        for(int j=0; j<m; j++){
            p[0][j] = true;
            a[n-1][j]  =  true;
        }
        bool next = true;

        while(next){
            next = false;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!p[i][j]){
                        if(i > 0 && p[i-1][j] && heights[i-1][j]  <= heights[i][j]){
                            p[i][j] = true;
                            next = true;
                        }
                        if(i < n-1 && p[i+1][j] && heights[i+1][j] <= heights[i][j]){
                            p[i][j] = true;
                            next = true;
                        }
                        if(j > 0 && p[i][j-1] && heights[i][j-1]  <= heights[i][j]){
                            p[i][j] = true;
                            next = true;
                        }
                        if(j < m-1 && p[i][j+1] && heights[i][j+1] <= heights[i][j]){
                            p[i][j] = true;
                            next = true;
                        }
                        
                    }

                    if(!a[i][j]){
                        if(i > 0 && a[i-1][j] && heights[i-1][j]  <= heights[i][j]){
                            a[i][j] = true;
                            next = true;
                        }
                        if(i < n-1 && a[i+1][j] && heights[i+1][j] <= heights[i][j]){
                            a[i][j] = true;
                            next = true;
                        }
                        if(j > 0 && a[i][j-1] && heights[i][j-1]  <= heights[i][j]){
                            a[i][j] = true;
                            next = true;
                        }
                        if(j < m-1 && a[i][j+1] && heights[i][j+1] <= heights[i][j]){
                            a[i][j] = true;
                            next = true;
                        }
                        
                    }
                }
            }
        }


        vector<vector<int>> result;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(p[i][j] && a[i][j])      result.push_back({i, j});
            }
        }

        return result;

    }
};