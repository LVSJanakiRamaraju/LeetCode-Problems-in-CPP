class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx, maxIdx;
        if(nums.size() == 1)    return 1;
        int minNum = nums[0], maxNum = nums[1];
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(minNum >= nums[i]){
                minNum = nums[i];
                minIdx = i;
            }
            if(maxNum <= nums[i]){
                maxNum = nums[i];
                maxIdx = i;
            }
        }

        cout<<minIdx<<maxIdx;

        int leftMin = minIdx + 1, rightMin = n - minIdx;
        int leftMax = maxIdx + 1, rightMax = n - maxIdx;
        int a = min(leftMin, rightMin), b  = min(leftMax, rightMax);

        int left = max(leftMin, leftMax), right = max(rightMin, rightMax);
        int first = min(left, right);

        left = leftMin + rightMax;
        right = leftMax + rightMin;
        int second = min(left, right);
        return min(first, second);
        
    }
};