class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int result =0;
        int count =0;

        vector<int> diff(n+1);
        for(int i=0; i<n; i++){
            while(count + diff[i] < nums[i]){
                result++;
                if(result > queries.size()) return -1;
            
                int left = queries[result-1][0], right = queries[result-1][1], val = queries[result-1][2];
                if(right >= i){
                    diff[max(left, i)] += val;
                    diff[right +1] -= val;
                }
            }
            count += diff[i];
        }

        return result;
    }
};