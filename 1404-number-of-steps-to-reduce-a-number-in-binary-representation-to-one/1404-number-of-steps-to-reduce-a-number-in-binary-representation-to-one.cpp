class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = n-1;
        int count = 0;
        for(int i = n-1; i> 0;i--){
            if(s[i]-'0'+count==1){
                ans++;
                count = 1;
            }
        }
        return ans + count;
    }
};