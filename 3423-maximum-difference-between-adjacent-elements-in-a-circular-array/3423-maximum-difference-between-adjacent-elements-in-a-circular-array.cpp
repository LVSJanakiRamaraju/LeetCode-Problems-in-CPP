class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int maxDiff = 0;
        for(int i=1; i<n; i++){
            maxDiff = max(maxDiff, abs(nums[i-1] - nums[i]));
        }
        return max(maxDiff, abs(nums[0] - nums[n-1]));
    }
};