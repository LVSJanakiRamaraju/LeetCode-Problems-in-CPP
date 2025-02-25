class Solution {
public:

    const int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result =0, oddCount=0, evenCount =1;
        int sum =0;
        for(int num : arr){
            sum += num;
            if(sum%2){
                result += evenCount;
                oddCount++;
            }else{
                result += oddCount;
                evenCount++;
            }
            result %= MOD;
        }

        return result;
    }
};