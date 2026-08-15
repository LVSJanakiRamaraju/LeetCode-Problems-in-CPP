class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor =0;
        bool allZ = true;
        for(int x : nums){
            totalXor ^= x;
            if(x != 0)  allZ = false;
        }
            if(totalXor != 0)return nums.size();
        
        if(!allZ)  return nums.size() -1;
        return 0;
    }
};