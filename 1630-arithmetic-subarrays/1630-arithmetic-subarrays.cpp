class Solution {
    bool solve(vector<int>& curr){
        int mx = INT_MIN, mn = INT_MAX;
        unordered_set<int> st;
        int n = curr.size();
        for(int num : curr){
            mn = min(mn, num);
            mx = max(mx, num);
            st.insert(num);
        }

        if((mx-mn)%(n-1))   return false;

        int diff = (mx-mn)/(n-1);
        int num = mn;
        while(num <= mx){
            if(st.find(num) == st.end())    return false;
            num += diff;
        }
        return true;
    }



public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n= nums.size(), m = l.size();
        vector<bool> result(m);
        for(int i=0; i<m; i++){
            vector<int> curr(nums.begin()+l[i], nums.begin() + r[i] + 1);
            result[i] = solve(curr);
        }
        return result;
    }
};