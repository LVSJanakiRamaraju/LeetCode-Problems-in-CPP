class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1] < 0)    return n;
        if(nums[0] > 0) return n;

        int low =0, high = n;
        int lower = n;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] < 0)   low = mid+1;
            else{
                high = mid;
            }
        }
        lower = low;

        low = 0, high = n;
        int upper = 0;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= 0)  low = mid + 1;
            else{
                high =  mid;
            }
        }
        upper = low;
        return max(lower, n-upper);
    }
};