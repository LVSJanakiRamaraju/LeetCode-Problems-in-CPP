class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> freq;

        for(char ch : s)    freq[ch]++;

        stack<char> st;
        string result;
        char min = 'a';

        for(char ch : s){
            st.push(ch);
            freq[ch]--;
            while(min != 'z' && freq[min] == 0) min++;

            while(!st.empty() && st.top() <= min){
                result.push_back(st.top());
                st.pop();
            }
        }

        return result;
    }
};