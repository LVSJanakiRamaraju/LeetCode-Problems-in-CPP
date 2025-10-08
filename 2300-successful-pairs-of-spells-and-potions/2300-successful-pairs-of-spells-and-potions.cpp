class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> result(n, 0);
        for(int i=0; i<n; i++){
            int a = spells[i];
            int b = ceil((success + a - 1)/a);
            auto low = lower_bound(potions.begin(), potions.end(), b) - potions.begin();
            
            result[i] = potions.size() - low;
            
        }
        return result;
    }
};