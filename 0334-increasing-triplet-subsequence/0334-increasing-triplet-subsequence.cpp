class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return false;
        int mn = INT_MAX, mx = INT_MAX;
       for(int i=0; i<n; i++){
        if(nums[i] <= mn)    mn = nums[i];
        else if(nums[i] <= mx)    mx = nums[i];
        else    return true;
        
       }
        return false;
    }
};