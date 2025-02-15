class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        for(int i=0; i<26; i++){
            mp['a' + i] = '0';
        }
        int i=0;
        for(char ch : key){
            if(ch != ' ' && mp[ch] == '0'){
                mp[ch] = 'a' + i;
                i++;
            }
        }
        string result;
        for(char ch : message){
            if(ch == ' ')   result.push_back(ch);
            else{
                result.push_back(mp[ch]);
            }
        }

        return result;
    }
};