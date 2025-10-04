class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left =0, right = n-1;
        int result = 0;
        while(left <= right){
            int m =  min(height[left], height[right]);
            result = max(result, m*(right - left));
            if(m != height[left])    right--;
            else   left++; 
        }
        return result;
    }
};