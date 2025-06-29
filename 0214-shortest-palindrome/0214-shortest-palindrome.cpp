class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = string(s.rbegin(), s.rend());
        string combinedString = s + "#" + rev;
        vector<int> prefixTable = buildPrefixTable(combinedString);
        int palindromeLength = prefixTable[combinedString.length() - 1];

        string suffix = rev.substr(0, s.length() - palindromeLength);
        return suffix + s;
    }

private:
    vector<int> buildPrefixTable(const string& s) {
        vector<int> prefixTable(s.length(), 0);
        int length = 0;
        for (int i = 1; i < s.length(); i++) {
            while (length > 0 && s[i] != s[length]) {
                length = prefixTable[length - 1];
            }
            if (s[i] == s[length]) {
                length++;
            }
            prefixTable[i] = length;
        }
        return prefixTable;
    }
};