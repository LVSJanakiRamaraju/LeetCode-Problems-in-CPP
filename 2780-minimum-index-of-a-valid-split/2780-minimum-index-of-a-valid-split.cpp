class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = nums[0], count =0;
        for(int num : nums){
            if(num == dominant) count++;
            else                count--;
            if(count == 0) {
                dominant = num;
                count++;
            }
        }

        count  =0;
        for(int num : nums){
            if(num == dominant) count++;
        }

        int left = 0, right = count, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == dominant){
                left++;
                right--;
            }
            if(left*2 > i+1 && right*2 > n-i-1)     return i;
        }
        return -1;
    }
};