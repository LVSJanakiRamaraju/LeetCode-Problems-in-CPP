class Solution {


public:
    string smallestNumber(string pattern) {
        string result ="";
        stack<char> st;
        for(int i=0; i<=pattern.size(); i++){
            st.push('0' + i+1);

            if(i == pattern.size() || pattern[i] == 'I'){
                while(!st.empty()){
                    result += st.top();
                    st.pop();
                }
            }
        }

        return result;
    }
};