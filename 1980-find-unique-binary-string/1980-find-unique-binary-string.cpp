class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for(int i=0; i<nums.size(); i++){
            char ch = nums[i][i] == '0' ? '1' : '0';
            result.push_back(ch);
        }
        return result;
        
    }
};
