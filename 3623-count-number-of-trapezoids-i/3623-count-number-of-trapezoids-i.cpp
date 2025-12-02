class Solution {
public:

    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> yg;
        for(auto& p : points){
            yg[p[1]]++;
        }
        vector<long long> hs;
        for(auto& [y, x] : yg){
            if(x >= 2){
                long long count = 1LL * x *(x-1)/2;
                hs.push_back(count);
            }
        }

        long long result =0, sum = 0, sumhs = 0;
        for(long long val : hs){
            sum = (sum + val) % MOD;
            sumhs = (sumhs + ( val * val) % MOD) % MOD;
        }

        result = (sum * sum % MOD - sumhs + MOD) % MOD;
        result = (result* ((MOD +1)/2)) % MOD;

        return (int) result;
    }
};