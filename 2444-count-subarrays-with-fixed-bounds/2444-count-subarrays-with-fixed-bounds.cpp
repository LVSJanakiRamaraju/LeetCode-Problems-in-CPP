class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result =0;
        int start = -1, minI = -1, maxI = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK)    start = i;
            if(nums[i] == minK) minI = i;
            if(nums[i] == maxK) maxI = i;
            result += max(0, min(minI, maxI) - start);
        }

        return result;
    }
};