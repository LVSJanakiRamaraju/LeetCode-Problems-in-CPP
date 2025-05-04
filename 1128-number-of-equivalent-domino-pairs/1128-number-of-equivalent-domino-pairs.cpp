class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result =0;
        vector<int> values(100);

        for(auto& it: dominoes){
            int val = it[0] < it[1] ? it[0]*10 + it[1] : it[1]*10 + it[0];
            result += values[val];
            values[val]++;
        }

        return result;
    }
};