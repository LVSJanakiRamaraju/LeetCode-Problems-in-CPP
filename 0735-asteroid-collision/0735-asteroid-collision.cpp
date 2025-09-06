class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto each : asteroids){
            bool add = true;
            while(!st.empty() && st.top() > 0 && each < 0){
                int top = st.top();
                st.pop();
                if(top == abs(each)){
                    add = false;
                    break;
                }
                else if(top > abs(each)){
                    st.push(top);
                    add = false;
                    break;
                }
                else{
                    add = true;
                }
                
            }
            if(add) st.push(each);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};