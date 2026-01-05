class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum  = 0;
        int val = INT_MAX;
        int count = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                sum += abs(matrix[i][j]);
                val = min(val, abs(matrix[i][j]));
                if(matrix[i][j] < 0)    count++;
            }
        }
        if(count%2)     return sum-val*2;
        return sum;
    }
};