class Solution {
private:
    int helper(char a, char b, string& s, int k){
        int maxDis = 0, dis =0;

        for(char ch : s){
            if(ch == a || ch == b)  dis++;
            else if(k--)    dis++;
            else{
                maxDis = max(maxDis, dis);
                dis--;
            }
        }
        return max(maxDis, dis);
    }


public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0;
        int maxDis =0, dis = 0;
        int i=0;
        for (char ch : s) {
            if (ch == 'N') y++;
            else if (ch == 'S') y--;
            else if (ch == 'E') x++;
            else if (ch == 'W') x--;
            dis = min(abs(x) + abs(y) + 2*k, i+1);
            maxDis = max(maxDis, dis);
            i++;
        }

        return maxDis;        
    }
};