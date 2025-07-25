class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxEle = nums[0], maxSum = 0;
        unordered_set<int> st;
        for(int num : nums){
            if(num > 0 && st.find(num) == st.end()){
                maxSum += num;
                st.insert(num);
            }
            
            maxEle = max(maxEle, num);
        }
        if(maxEle < 0)  return maxEle;
        return maxSum;
    }
};