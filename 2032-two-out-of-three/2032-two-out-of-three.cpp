class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool mp[3][101] = {};
        for(int num : nums1){
            mp[0][num] = true;
        }
        for(int num : nums2){
            mp[1][num] = true;
        }
        for(int num : nums3){
            mp[2][num] = true;
        }
        vector<int> result;
        for(int i=1; i<=100; i++){
            if(mp[0][i] + mp[1][i] + mp[2][i] > 1)  result.push_back(i);
        }

        return result;;
    }
};