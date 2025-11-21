#define pb push_back
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) mpp[nums[i]].pb(i);

        vector<int> minDist(n, -1);

        for(auto &entry : mpp) {
            vector<int> &idxs = entry.second;
            int k = idxs.size();
            if(k < 2) continue;

            for(int i = 0; i < k; i++) {
                int prevIdx = idxs[(i - 1 + k) % k];
                int d1 = (idxs[i] - prevIdx + n) % n;

                int nxtIdx = idxs[(i + 1) % k];
                int d2 = (nxtIdx - idxs[i] + n) % n;

                minDist[idxs[i]] = min(d1, d2);
            }
        }

        int q = queries.size();
        vector<int> ans(q);
        for(int i = 0; i < q; i++) ans[i] = minDist[queries[i]];

        return ans;
    }
};