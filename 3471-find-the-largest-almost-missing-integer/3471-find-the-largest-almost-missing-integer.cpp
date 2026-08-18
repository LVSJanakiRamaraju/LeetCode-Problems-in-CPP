class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of size-k subarrays containing x
        vector<int> count(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            // Avoid counting the same number twice
            // inside the same subarray.
            bool present[51] = {};

            for (int j = i; j < i + k; j++) {
                present[nums[j]] = true;
            }

            // This subarray contains each of these values once
            for (int x = 0; x <= 50; x++) {
                if (present[x]) {
                    count[x]++;
                }
            }
        }


        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};