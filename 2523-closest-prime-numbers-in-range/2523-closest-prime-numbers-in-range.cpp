class Solution {
private:
    bool isprime(int n){
        if(n == 1) return false;
        long long num = n;
        for(long long i=2; i*i <= num;i++){
            if(num%i==0) return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> result;

        for(int i=left; i<=right; i++){
            if(i%2 == 0 && i>2) continue;
            if(isprime(i)){
               if(!result.empty() && i<= result.back() +2)  return {result.back(), i};
               result.push_back(i);
            }
        }
        if(result.size() < 2)   return {-1, -1};

        vector<int> ans;
        int minDiff = 1e6;
        for(int i=1; i<result.size(); i++){
            int diff = result[i] - result[i-1];
            if(diff < minDiff){
                minDiff = diff;
                ans = {result[i-1], result[i]};
            }
        } 
        return ans;
    }
};