class Solution {
public:
    bool checkStrings(string s1, string s2) {

        vector<int> count(64, 0);

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 5;
            count[s1[i] - 'a' + offset]++;
            count[s2[i] - 'a' + offset]--;
        }

        for (int i = 0; i < 64; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};