class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), totalCount =0;
        unordered_map<int, int> freq;

        for(int a =0; a < n; a++){
            for(int b = a+1; b < n; b++){
                int pro = nums[a]*nums[b];
                freq[pro]++;
            }
        }

        for(auto [pro, count] : freq){
            totalCount += 8 * ((count -1)*(count)/2);
        }
        return totalCount;

    }
};