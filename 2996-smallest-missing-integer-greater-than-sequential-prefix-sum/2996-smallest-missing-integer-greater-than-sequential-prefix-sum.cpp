class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int prefix = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix += nums[i];
            } else {
                break;
            }
        }

        while (num_set.count(prefix)) {
            prefix += 1;
        }

        return prefix;
    }
};