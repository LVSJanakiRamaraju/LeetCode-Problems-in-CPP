class Solution {
  private:
    int helper(vector<int>& nums, int mid){
        int count =0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] <= mid)  count++;
        }

        return count;
    }



public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min = 0, max = nums[n-1] - nums[0];

        while(min < max){
            int mid = min + (max - min)/2;
            if(helper(nums, mid) >= p){
                max = mid;
            }
            else{
                min = mid +1;
            }
        }

        return min;
    }
};