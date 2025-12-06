class Solution {
public:
    const int MOD = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {

        vector<int> dor = nums;
        int n = nums.size();
        vector<int> dp(n+1, 0);
        vector<int> prefix(n+2, 0);
        dp[0] = 1;
        prefix[1]= 1;

        deque<int> max, min;

        int l= 0;

        for(int r=0; r<n; r++){
            while(!max.empty() && nums[r] > max.back()) max.pop_back();
            max.push_back(nums[r]);

            while(!min.empty() && nums[r] < min.back()) min.pop_back();
            min.push_back(nums[r]);

            while(max.front() - min.front() > k){
                if(max.front() == nums[l]) max.pop_front();
                if(min.front() == nums[l]) min.pop_front();
                ++l;
            }


            dp[r+1] = (prefix[r+1] - prefix[l] + MOD)%MOD;
            prefix[r+2] = (prefix[r+1] + dp[r+1])%MOD;
        }

        return dp[n];
    }
};