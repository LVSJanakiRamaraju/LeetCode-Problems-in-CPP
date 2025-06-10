class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int minEven =INT_MAX, maxOdd = 0;

        for(int i=0; i<26; i++){
            if(freq[i]){
                if(freq[i]%2)   maxOdd = max(maxOdd, freq[i]);
                else    minEven = min(minEven, freq[i]);
            }
        } 

        return maxOdd - minEven;
    }
};