class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n= mat.size(), m = mat[0].size();

        vector<int> result;
        vector<int> inter;
        for(int i=0; i<m+n -1; i++){
            int r = i < m ? 0 : i-m+1;
            int c = i < m ? i : m-1;

            while(r < n && c > -1){
                inter.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(i %2 == 0)   reverse(inter.begin(), inter.end());

            for(int ele : inter){
                result.push_back(ele);
            }

            inter.clear();
        }

        return result;
    }
};