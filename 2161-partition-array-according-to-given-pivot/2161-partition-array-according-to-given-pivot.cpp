class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n ,pivot);
        int left =0, right = n-1;
        for(int i=0, j= n-1; i<n; i++, j--){
            if(nums[i] < pivot)
                result[left++] = nums[i];
            if(nums[j] > pivot)
                result[right--] = nums[j];
        }
        return result;

    }
};