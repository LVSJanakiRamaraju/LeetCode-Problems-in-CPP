class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        int len = nums.size();
        for(int i=0; i< len; i++){
            if(nums[i]%2 == 0)  ans += nums[i];
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0], index = queries[i][1];
            if (nums[index] % 2 == 0) ans -= nums[index];
            nums[index] += val;
            if (nums[index] % 2 == 0) ans += nums[index];
            result[i] = ans;
        }

        return result;

    }
};