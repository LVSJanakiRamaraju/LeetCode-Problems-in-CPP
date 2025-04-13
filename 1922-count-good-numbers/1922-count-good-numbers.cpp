#define MOD 1000000007

class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(int n) {
        int evenCount = (n + 1) / 2;  
        int oddCount = n / 2;        

        long long evenWays = modPow(5, evenCount, MOD);
        long long oddWays = modPow(4, oddCount, MOD);

        return (evenWays * oddWays) % MOD;
    }
};