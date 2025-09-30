class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n == 2)  return (nums[0] + nums[1])%10;

        while(n-- >= 1){
            for(int i=0; i< n; i++){
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }

        return nums[0];
    }
};