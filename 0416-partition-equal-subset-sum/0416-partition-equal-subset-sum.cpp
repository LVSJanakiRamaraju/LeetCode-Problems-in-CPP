class Solution {


public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        if(totalSum%2)  return false;
        totalSum /=2 ;

        vector<bool> prev(totalSum+1, false), curr(totalSum+1, false);
        prev[0] = true;
        curr[0] = true;

        if(nums[0] <= totalSum) prev[nums[0]] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=totalSum; j++){
                bool notPick = prev[j];
                bool pick =  (nums[i] <= j) ? prev[j-nums[i]] : false;
                curr[j] = notPick || pick;
            }
            prev = curr;

        }
        return prev[totalSum];
        

    }
};