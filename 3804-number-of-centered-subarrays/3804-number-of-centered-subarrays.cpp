class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result =0, sum  =0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                sum += nums[j];
                st.insert(nums[j]);
                if(st.find(sum) != st.end())    result++;
            }
            st.clear();
            sum =0;
        }
        return result;
    }
};