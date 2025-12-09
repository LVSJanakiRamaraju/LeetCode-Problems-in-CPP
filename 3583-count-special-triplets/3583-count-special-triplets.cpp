class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();

        long long count = 0;
        unordered_map<int, int> leftCount;
        unordered_map<int, int> rightCount;

        for(int num : nums)  rightCount[num]++;

        for(int i=0; i<n; i++){
            rightCount[nums[i]]--;
            int target = 2 * nums[i];
            long long left = leftCount[target];
            long long right = rightCount[target];
            count = (count + left*right)%MOD;

            leftCount[nums[i]]++;
        }

        return (int)count;
    }
};