class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int result =0;
        vector<int> arr;
        for(auto row : grid){
            for(int col : row){
                if(col %x != grid[0][0]%x) return -1;
                arr.push_back(col);
            }
        }

        int n = arr.size();
        nth_element(arr.begin(), arr.begin() + n/2, arr.end());
        int mid = arr[n/2];
        for(int num: arr){
            if(num%x != mid%x)  return -1;
            result += abs(num - mid)/x;
        }

        return result;
    }
};