class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for(auto row : grid){
            for(int col : row){
                arr.push_back(col);
            }
        }
        int n = arr.size();
        for(int i=0; i<n; i++){
            while(arr[i] != i+1 && arr[i] != arr[arr[i] -1]){
                swap(arr[i], arr[arr[i] -1]);
            }
        }
        vector<int> result;
        for(int i=0;i<n; i++){
            if(arr[i] != i+1){
                result.push_back(arr[i]);
                result.push_back(i+1);
            }
        }

        return result;
    }
};