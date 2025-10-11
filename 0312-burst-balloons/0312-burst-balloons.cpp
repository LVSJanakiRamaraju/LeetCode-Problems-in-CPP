class Solution {
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i > j)   return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int maxVal = INT_MIN;

        for(int k=i; k<=j; k++){
            int currVal = arr[i-1]*arr[k]*arr[j+1] + solve(i, k-1, arr, dp) + solve(k+1, j, arr, dp);
            maxVal = max(currVal, maxVal);
        }

        return dp[i][j] = maxVal;
        
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        vector<int> arr = {1};
        for(int num : nums){
            arr.push_back(num);
        }
        arr.push_back(1);

        return solve(1, n, arr, dp);
    }
};