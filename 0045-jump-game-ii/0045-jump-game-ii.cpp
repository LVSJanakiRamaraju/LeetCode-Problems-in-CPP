class Solution {
public:
    int jump(vector<int>& nums) {
        int start =0, end=0, jumps =0;
        while(end < nums.size()-1){
            int f =0;
            for(int i=start; i<=end; i++){
                f = max(f, i + nums[i]);
            }
            start = end+1;
            end = f;
            jumps++;
        }

        return jumps;
    }
};