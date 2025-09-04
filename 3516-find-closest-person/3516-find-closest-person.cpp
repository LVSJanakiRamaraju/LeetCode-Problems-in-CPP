class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xReach = abs(z-x);
        int yReach = abs(z-y);
        if(xReach == yReach)    return 0;
        return xReach < yReach ? 1 : 2;
    }
};