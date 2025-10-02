class Solution {
public:
    int maxBottlesDrunk(int B, int E) {
     return B + (((-2*E) + 3 + sqrt(4*E*E + 8*B - 12*E + 1))/2);
    }
};