class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2, i = 0, pro = 1;
        for(int j= 0; j < nums.size(); j++){
            while(gcd(pro, nums[j]) > 1)   pro /= nums[i++];

            pro *= nums[j];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};