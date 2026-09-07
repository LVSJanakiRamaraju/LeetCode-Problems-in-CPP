class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size(), m = 1e9 + 7;
        int ans = 0;
        vector<int> freq(26, 0);

        for(char ch : s){
            int idx = ch - 'a';
            int curr = (1 + ans - freq[idx] + m)%m;
            ans = (ans + curr)%m;
            freq[idx] = (freq[idx] + curr)%m;
        }
        return ans;
    }
};