class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxLen =0;
        vector<vector<int>> evenOdd ={{0, 0}, {1, 1}, {0, 1}, {1, 0}};
        for(auto ops : evenOdd){
            int len =0;
            for(int num : nums){
                if(num%2 == ops[len%2]) len++;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};