class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int idx =-1, count =0;
        if(n == 2)  return abs(nums[0] - nums[1]);
        int i;
        for(i=1; i<n; i++){
            if(nums[i-1] < nums[i])     idx = i;
            else break;

        }
        if(i < n-1 && nums[i] == nums[i+1]) i++;
        for(;i<n-1; i++){
            if(nums[i] <= nums[i+1])    return -1;
        }
        if(idx < n-1 && nums[idx] == nums[idx+1]){
            long long sum =0;
            for(int i=0; i<=idx; i++)   sum += nums[i];
            for(int i=idx+1; i<n; i++)  sum -= nums[i];
            return abs(sum);
        }
        long long sum =0;
        for(int i=0; i<idx; i++)    sum += nums[i];
        for(int i=idx+1; i<n; i++)  sum -= nums[i];
        sum = min(abs(sum+nums[idx]), abs(sum - nums[idx]));
        return abs(sum);
    
    }
};