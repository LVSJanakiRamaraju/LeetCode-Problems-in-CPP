class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            result.push_back(nums[num]);
        }

        return result;
    }
};