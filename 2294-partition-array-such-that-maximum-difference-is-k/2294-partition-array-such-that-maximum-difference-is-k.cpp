class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result =1, min = nums[0];
        for(int num : nums){
            if(num - min  > k){
                result++;
                min = num;
            }
        }

        return result;
    }
};