class Solution {
public:
int index = 0;
    string reverseParentheses(string s) {
        string result;
        while(index < s.size()){
            if(s[index] == ')'){
                reverse(result.begin(), result.end());
                index++;
                return result;
            }
            else if(s[index] == '('){
                index++;
                string str = reverseParentheses(s);
                result += str;
            }
            else{
                result += s[index];
                index++;
                
            }
        }
        return result;
    }
};