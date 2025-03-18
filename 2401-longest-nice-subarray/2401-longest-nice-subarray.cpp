class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits = 0;
        int left =0;
        int maxLen =0, n = nums.size();
        for(int right =0; right < n; right++){
            while((bits & nums[right]) !=0){
                bits ^= nums[left];
                left++;
            }
            bits |= nums[right];
            maxLen =  max(maxLen, right - left +1);
        }
        return maxLen;
    }
};