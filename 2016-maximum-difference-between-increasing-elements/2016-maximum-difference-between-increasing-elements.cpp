class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = -1, min = nums[0];
        
        for(int i=1; i<n; i++){
            if(min < nums[i]){
                result = max(result, nums[i] - min);
            }else{
                min = nums[i];
            }
        }

        return result;
    }
};