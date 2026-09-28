class Solution {
public:
    int maxDepth(string s) {
        int vps = 0;
        int count = 0;
        for(int i= 0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                if(count>vps){
                    vps = count;
                }
            }
            else{
                if(s[i] == ')'){
                    count--;
                }
            }
        }
        return vps;
    }
};