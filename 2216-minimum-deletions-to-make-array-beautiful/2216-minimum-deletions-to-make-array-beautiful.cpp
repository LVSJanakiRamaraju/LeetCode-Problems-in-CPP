class Solution {
public:
    int minDeletion(vector<int>& nums) {
       int del = 0;
       int n = nums.size();
       for(int i=0; i<n-1; i++){
        if(nums[i] != nums[i+1]){
            i++;
        }
        else{
            del++;
        }
       } 

       return del + (n - del)%2;
    }
};