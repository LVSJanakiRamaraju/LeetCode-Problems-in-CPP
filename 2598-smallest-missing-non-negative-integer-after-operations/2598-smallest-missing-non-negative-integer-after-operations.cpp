class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<bool> arr(value, false);
        for(int i =0; i<n; i++){
            int x = (value + (nums[i]%value)) %value;
            arr[x] = true;
        }
        for(int i=0; i<value; i++){
            if(!arr[i]) return i;
        }
        return value;
    }
};