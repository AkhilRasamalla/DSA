class Solution {
public:
    const long long MOD = 1e9 + 7;

    //ITERATIVE APPROACH THE DOWN FUNCTION CALL IS SAME FOR BOTH RECURSIVE ALSO

    // long long modPow(long long base, long long exp, long long mod) {
    //     long long result = 1;
    //     base %= mod;
    //     while (exp > 0) {
    //         if (exp % 2 == 1) {
    //             result = (result * base) % mod;
    //         }
    //         base = (base * base) % mod;
    //         exp /= 2;
    //     }
    //     return result;
    // }

    // RECURSIVE APPROACH

    long long modPow(long long base, long long exp,long long mod){
        if(exp==0) return 1;
        long long half = modPow(base,exp/2,mod);
        long long result = (half * half) % mod;
        if(exp % 2 ==1){
            result = (result * base) % mod;

        }
        return result;
    }


    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long part1 = modPow(5, evenCount, MOD);
        long long part2 = modPow(4, oddCount, MOD);

        return (int)((part1 * part2) % MOD);
    }
};