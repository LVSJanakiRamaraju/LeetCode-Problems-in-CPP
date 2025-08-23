class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;
        int rInd = nums.size() - 1;

        for (int i = 0;i<k;i++) lsum += nums[i];
        maxsum = lsum;
        for(int i = k-1;i>=0;i--) {
            lsum -= nums[i];
            rsum += nums[rInd];
            rInd--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};