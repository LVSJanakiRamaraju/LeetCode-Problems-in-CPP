class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        long long maxSum =0, sum =0;
        int i=0, n = nums.size(); 
        for(int j=0; j<n; j++){
            while(seen.find(nums[j]) != seen.end()){
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;
                
            }
            sum += nums[j];
            seen.insert(nums[j]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};