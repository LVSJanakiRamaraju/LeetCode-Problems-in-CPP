class Solution {
public:
    int trap(vector<int>& height) {
        int mapLen = height.size(); 

        //Created two arrays to store the maximum heights from left and right
        vector<int> leftMaxHeight(mapLen, 0), rightMaxHeight(mapLen, 0);
        leftMaxHeight[0] = height[0], rightMaxHeight[mapLen -1] = height[mapLen -1];

        //find maximum heights and store in arr
        for(int currMap =1; currMap < mapLen; currMap++){
            leftMaxHeight[currMap] = max(leftMaxHeight[currMap-1], height[currMap]);
            rightMaxHeight[mapLen - currMap -1] = max(rightMaxHeight[mapLen - currMap], height[mapLen - currMap -1 ]);
        }

        int trappedWater = 0;
        for(int currMap =0; currMap < mapLen; currMap++){
            trappedWater += min(leftMaxHeight[currMap], rightMaxHeight[currMap]) - height[currMap];
        }

        return trappedWater;
    }
};