class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left =1, right = 1LL * ranks[0] * cars * cars;

        while(left < right){
            int mid = (left + right)/2;
            int repaired = 0;
            for(int rank : ranks)   repaired += sqrt(1.0 * mid/rank);

            if(repaired < cars) left = mid+1;
            else    right = mid;
        }
        return left;
    }
};