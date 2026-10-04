class Solution {
public:
    bool checkValidString(string s) {
        
       int left = 0;
       int right = 0;
       for(char c : s){
            if(c == '('){
                left++;
                right++;
            }
            else if(c == ')'){
                left--;
                right--;
            }
            else{
                left--;
                right++;
            }
            if(right < 0){
                return false;
            }
            if(left < 0){
                left = 0 ;
            }
       }
       
    return left==0;
    }
};