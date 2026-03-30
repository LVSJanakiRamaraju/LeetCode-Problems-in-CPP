class Solution {
public:
    bool checkStrings(string s1, string s2) {

        vector<int> count(128, 0);

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 6;
            count[s1[i] - 'a' + offset]++;
            count[s2[i] - 'a' + offset]--;
        }

        for (int i = 0; i < 128; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};