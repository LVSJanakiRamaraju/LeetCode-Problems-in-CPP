class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int ans =0;
        for(int i = 0; i< m.size();++i){
            for(int j =0; j<m[0].size(); ans += m[i][j++]){
                if (m[i][j] && i && j)
                    m[i][j] += min({m[i - 1][j - 1], m[i - 1][j], m[i][j - 1]});
            }
        }
        return ans;
    }
};