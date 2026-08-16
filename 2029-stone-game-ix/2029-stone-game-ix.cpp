class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int x= 0, y=0, z = 0;
        for(int stone : stones){
            if(stone%3 == 1)    x++;
            else if(stone%3 == 2)   y++;
            else    z++;
        }

        if(z%2 == 0)    return x > 0 && y > 0;
        return abs(x-y) > 2;
    }
};