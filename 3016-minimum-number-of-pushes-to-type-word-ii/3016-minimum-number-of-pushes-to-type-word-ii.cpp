class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for(char ch : word){
            count[ch-'a']++;
        }
        sort(count.begin(), count.end());
        int ans = 0;
        int i = 25;
 
        while(i >= 0){
            if(i >= 18){
                ans += count[i] * 1;
            }
            else if(i >= 10){
                ans += count[i] * 2;
            }
            else if(i >=2){
                ans += count[i] * 3;
            }
            else{
                ans += count[i] * 4;
            }
            i--;
        }
        return ans;
    }
};