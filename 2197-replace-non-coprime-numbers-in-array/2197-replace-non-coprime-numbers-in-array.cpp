class Solution {
private:
    int gcd(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (b < a)
            return gcd(a % b, b);
        return gcd(a, b % a);
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        int g = 0;
        for(int i=1; i<n; i++){
            int x = nums[i];
            while(!st.empty() && gcd(st.top(), x) > 1){
                g = gcd(st.top(), x);
                x = (int)(x * st.top()/g);
                st.pop();
            }
            st.push(x);
            
        }
        int len = st.size();
        vector<int> ans(len, 0);
        len--;
        while(!st.empty()){
            ans[len--] = st.top();
            st.pop();
        }

        return ans;

    }
};