class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int A = capacityA, B = capacityB, n = plants.size();
        int result=0;
        for(int i=0; i<(n+1)/2; i++){
            if(i == n-i-1){
                if(A < plants[i] && B < plants[i])  result++;
                break;
            }
            if(plants[i] > A){
                result++;
                A = capacityA;
            }
            else    A -= plants[i];
            if(plants[n-i-1] > B){
                result++;
                B = capacityB;
            }
            else    B -= plants[n-i-1];
        }

        return result;
    }
};