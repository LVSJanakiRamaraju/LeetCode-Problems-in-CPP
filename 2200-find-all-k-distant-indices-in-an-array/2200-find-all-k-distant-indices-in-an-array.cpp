class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result = {-1};
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == key){
                int idx = max(result.back()+1, i-k>0? i-k: 0);
                for(; idx <= i+k && idx < n; idx++){
                    result.push_back(idx);
                }
            }
        }

        return vector<int>(result.begin() + 1, result.end());
    }
};