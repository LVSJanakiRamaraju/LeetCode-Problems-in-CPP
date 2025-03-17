class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> arr(501, 0);
        for(int num : nums){
            arr[num]++;
        }
        for(int count : arr){
            if(count%2) return false;
        }
        return true;
    }
};