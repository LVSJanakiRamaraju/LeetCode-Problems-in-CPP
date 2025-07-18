class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        vector<int> result(n, -1);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            int idx = i % n;
            while(!st.empty() && st.top() <= arr[idx]){
                st.pop();
            }
            if(i < n){
                if(st.empty())  result[idx] = -1;
                else result[idx] = st.top();
            }

            st.push(arr[idx]);
        }


        return result;
    }
};