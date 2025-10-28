class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int right = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (left - right < 2 && left -  right >= 0) {
                    ans += 1;
                } 
                if(right - left < 2 && right - left >= 0){
                    ans += 1;
                }
            }
            left += nums[i];
            right -= nums[i];
        }
        return ans;
    }
};