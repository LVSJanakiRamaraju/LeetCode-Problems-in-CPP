class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxP =0;
        for(int i= n-1; i>=2; i--){
            int a = nums[i], b = nums[i-1], c = nums[i-2];
            if(a+b > c && a+c > b && b+c > a){
                maxP = max(maxP, a+ b +c);
            }
        }
        return maxP;
    }
};