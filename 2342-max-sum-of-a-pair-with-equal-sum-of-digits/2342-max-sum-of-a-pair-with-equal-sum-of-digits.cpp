class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result =-1;
        vector<int> digitSum(82, 0);

        for(int ele : nums){
            int sum = 0;
            int num = ele;
            while(ele){
                sum += ele%10;
                ele /= 10;
            }
            if(digitSum[sum])       result = max(result, digitSum[sum] + num);
            digitSum[sum] = max(digitSum[sum], num);
        }
        return result;
    }
};