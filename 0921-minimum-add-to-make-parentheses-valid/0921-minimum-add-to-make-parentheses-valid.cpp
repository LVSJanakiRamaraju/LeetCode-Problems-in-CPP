class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(!st.empty()){
                if(ch == ')' && st.top() == '(')    st.pop();
                else st.push(ch);
            }
            else{
                st.push(ch);
            }
        }
        return st.size();
    }
};