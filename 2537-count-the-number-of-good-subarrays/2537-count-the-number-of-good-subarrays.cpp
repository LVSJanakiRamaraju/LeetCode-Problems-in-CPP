class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long result=0;
        int count = 0, right  =-1;
        for(int left =0; left < n; left++){
            while(count < k && right +1 < n){
                right++;
                count += freq[nums[right]];
                freq[nums[right]]++;
            }
            if(count >= k)  result += n - right;

            freq[nums[left]]--;
            count -= freq[nums[left]];
        }

        return result;
    }
};