class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int i=0, j = n-1, count = 0;
        while(i <= j){
            if(nums[i] + nums[j] <= target){
                count = (count + power[j-i])% MOD;
                i++;
            }
            else{
                j--;
            }
        }

        return count;
    }
};