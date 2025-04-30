class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result =0;
        for(int num : nums){
            int len = (int) floor(log10(num));
            if(len%2)  result++;
        }

        return result;
    }
};