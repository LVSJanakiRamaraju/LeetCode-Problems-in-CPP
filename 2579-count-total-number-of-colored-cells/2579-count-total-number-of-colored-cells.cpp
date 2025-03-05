class Solution {
public:
    long long coloredCells(int n) {
        long long totalCells =1;
        long long newCells = 4;
        while(n > 1){
            totalCells += newCells;
            newCells += 4;
            n--;
        }
        return totalCells;
    }
};