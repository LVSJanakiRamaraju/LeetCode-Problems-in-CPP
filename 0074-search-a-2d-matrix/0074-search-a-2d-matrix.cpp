class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m-1;
        while(top < bottom){
            int mid = top + (bottom-top)/2;
            if(matrix[mid][0] <= target)    top = mid;
            else bottom = mid;

            if(top == bottom-1) break;
        }

        int left =0, right = n-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(matrix[top][mid] == target)  return true;
            if(matrix[top][mid] < target)   left = mid+1;
            else right = mid -1;
        }
        left = 0, right =n-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(matrix[bottom][mid] == target)  return true;
            if(matrix[bottom][mid] < target)   left = mid+1;
            else right = mid -1;
        }
        return false;
        
    }
};