class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), result =0;;

        for(int i=0; i<n; i++){
            for(int j=0; j< m; j++){
                if(matrix[i][j] != 0 && i > 0)  matrix[i][j] += matrix[i-1][j];
            }
            vector<int> last = matrix[i];
            
            sort(last.rbegin(), last.rend());
            for(int i=0; i<m; i++)  result = max(result, last[i]*(i+1));
        }
        return result;
    }
};