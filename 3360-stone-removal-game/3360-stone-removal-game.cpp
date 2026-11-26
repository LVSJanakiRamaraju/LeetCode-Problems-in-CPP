class Solution {
public:
    bool canAliceWin(int n, int take = 10) {
        return n >= take && !canAliceWin(n - take, take - 1);
    }
};