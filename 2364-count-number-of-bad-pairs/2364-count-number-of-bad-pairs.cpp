class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int diff = i - nums[i];
            int count = mp[diff];
            badPairs += i - count;
            mp[diff]++;
        }
        return badPairs;
    }
};