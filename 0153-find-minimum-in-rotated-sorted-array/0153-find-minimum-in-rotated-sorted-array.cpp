class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return min(nums[0],nums[1]);
        int low=0;
        int high=n-1;
        while (low<high) {
            int mid=low+(high-low)/2;
            if (nums[mid]>nums[high]){
                low=mid+1;
            } else {
                high=mid;
            }
        }
        return nums[low];
    }
};