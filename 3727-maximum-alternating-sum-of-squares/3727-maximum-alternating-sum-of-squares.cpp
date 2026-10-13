
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans += squares[n - 1 - i];
            ans -= squares[i];
        }

        if (n % 2 == 1) {
            ans += squares[n / 2];
        }

        return ans;
    }
};
