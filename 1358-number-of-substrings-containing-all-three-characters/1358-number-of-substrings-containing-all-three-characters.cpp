class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int result =0, n = s.size();
        int left =0, right =0;
        while(right < n){
            mp[s[right]]++;
            while(mp.size() ==3){
                result += n - right;
                mp[s[left]]--;
                if(mp[s[left]] == 0)    mp.erase(s[left]);
                left++; 
            }
            right ++;
        }
        return result;
    }
};