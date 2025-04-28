class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long result =0, sum =0;
        int i=0, j=0;
        for(; j<n; j++){
            sum += nums[j];
            while(i <= j && sum*(j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            result += j-i+1;
        }

        return result;
    }
};