class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result =0, maxDiff =0, maxVal =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            result = max(result, maxDiff*nums[i]);
            maxDiff = max(maxDiff, maxVal - nums[i]);
            maxVal = max(maxVal, static_cast<long long>(nums[i]));
        }
        return result;
    }
};