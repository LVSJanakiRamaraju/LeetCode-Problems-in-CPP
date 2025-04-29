class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int i=0, j=0, count=0;
        long long result =0;
        for(; j<n; j++){
            if(nums[j] == maxEle)   count++;
            while(count == k){
                
                if(nums[i] == maxEle)   count--;
                i++;
            }
            result += i;
        }
        return result;
    }
};