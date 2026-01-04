class Solution {
public:

    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0)    return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result =0;
        for(int n : nums){
            int root = round(cbrt(n));
            if(root * root * root == n && isPrime(n))   result += (1 + root + root*root + root*root*root);

            else{
                for(int i=2; i*i <= n; i++){
                    if(n%i == 0){
                        int j = n/i;
                        if(i != j && isPrime(i) && isPrime(j)){
                            result += (1 + i + j + n);
                            break;
                        }
                    }
                }
            }
            cout<<result<<endl;
        }
        return result;

    }
};