class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
       int n = nums.size();

        const long long BASE = 1000003;
        const long long MOD = 1000000007;

        vector<long long> power(n + 1, 1);
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            power[i + 1] = power[i] * BASE % MOD;
            pref[i + 1] = (pref[i] * BASE + nums[i]) % MOD;
        }

        auto check = [&](int len) -> bool {
            unordered_map<long long, int> freq;
            freq.reserve(2 * n);
            freq.max_load_factor(0.67);

            for (int i = 0; i + len <= n; i++) {
                long long h = (pref[i + len] -
                               pref[i] * power[len] % MOD + MOD) % MOD;

                if (++freq[h] == 1) {
                    // Continue counting before deciding uniqueness.
                }
            }

            for (auto& [hash, count] : freq) {
                if (count == 1) return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};