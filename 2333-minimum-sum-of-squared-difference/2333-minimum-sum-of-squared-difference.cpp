class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<long long> diff(n);
        long long total = 0, maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        // Enough operations to make every difference zero
        if (k >= total)
            return 0;

        // Binary search the smallest feasible maximum difference
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid)
                    needed += d - mid;
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long x = low;
        long long used = 0;
        long long answer = 0;
        long long countAtLeastX = 0;

        for (long long d : diff) {
            if (d > x) {
                used += d - x;
                answer += x * x;
                countAtLeastX++;
            } else {
                answer += d * d;
                if (d == x)
                    countAtLeastX++;
            }
        }

        // Spend remaining operations by reducing x to x - 1.
        long long remaining = k - used;
        answer -= remaining * (2 * x - 1);

        return answer;
    }
};