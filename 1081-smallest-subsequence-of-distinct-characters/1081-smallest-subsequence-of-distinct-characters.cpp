class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0), have(26, 0);
        string result = "";
        for(char ch : s){
            freq[ch - 'a']++;
        }
        for(char ch : s){
            freq[ch - 'a']--;
            if(have[ch - 'a']++ > 0)    continue;
            while(!result.empty() && result.back() > ch && freq[result.back() - 'a'] > 0){
                have[result.back() - 'a'] = 0;
                result.pop_back();
            }
            result.push_back(ch);
        }

        return result;
    }
};