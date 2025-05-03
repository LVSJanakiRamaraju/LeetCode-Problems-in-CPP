class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result1 =0;
        int n = tops.size();
        for(int i=1; i<n; i++){
            if(tops[i] == tops[i-1])    continue;
            if(bottoms[i] == tops[i-1]){
                result1++;
                swap(tops[i], bottoms[i]);
            }
            else return -1;
        }
        
        int result2 = 1;
        for(int i=1; i<n; i++){
            if(tops[i] == bottoms[i-1])    continue;
            if(bottoms[i] == bottoms[i-1]) {
                result2++;
                swap(tops[i], bottoms[i]);
            }
            else return result1;
        }
        
        return min(result1, result2);
    }
};