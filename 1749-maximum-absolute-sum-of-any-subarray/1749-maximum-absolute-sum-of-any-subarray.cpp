class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum =0, minSum = 0, maxSum = 0;
        for(int num : nums){
            sum+= num;
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
        }
        return maxSum - minSum;
    }
};