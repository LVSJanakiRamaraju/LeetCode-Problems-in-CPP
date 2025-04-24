class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count =0;
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        int right =0;
        for(int left =0; left<nums.size(); left++){
            if(left > 0){
                freq[nums[left-1]]--;
                if(freq[nums[left-1]] == 0)   freq.erase(nums[left-1]);
            }

            while(right < nums.size() && freq.size() < st.size()){
                freq[nums[right]]++;
                right++;
            }

            if(freq.size() == st.size()){
                count += nums.size() - right + 1;
            }
        }

        return count;

    }
};