class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int count = 0;
        long long total_diff = 0;
        long long diff = 0;
        long long min_diff = numeric_limits<long long>::max();
        for(auto i : nums){
            diff = (i^k) - i;
            if (diff > 0){
                total_diff += diff;
                count++;
            }
            min_diff = min(min_diff, abs(diff));
        }
        if(count % 2) total_diff -= min_diff;
        return accumulate(nums.begin(), nums.end(),0ll) + total_diff;
    }
};