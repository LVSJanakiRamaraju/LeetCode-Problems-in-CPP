class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n < k)   return s;
        stack<pair<char, int>> st;
        for(char ch : s){
            if(st.empty())  st.push({ch, 1});
            else if(st.top().first != ch)   st.push({ch, 1});
            else{
                pair<char, int> curr = st.top();
                st.pop();
                if(curr.second + 1 == k)   continue;
                st.push({ch, curr.second+1});
            }
        }

        n = st.size();
        string result;
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            for(int i=0; i<curr.second; i++){
                result += curr.first;
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }
};