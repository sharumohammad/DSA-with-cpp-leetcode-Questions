#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodArrays(int n, int m, int k)
    {
        const int MOD = 1'000'000'007;

        // Step 1: Handle edge cases
        if (k < 0 || k > n - 1)
        {
            return 0;
        }

        // Step 2: Precompute factorials
        vector<long long> factorial(n, 1);
        for (int i = 1; i < n; i++)
        {
            factorial[i] = factorial[i - 1] * i % MOD;
        }

        // Step 3: Precompute modular inverses using modular exponentiation
        vector<long long> invFact(n);
        invFact[n - 1] = powMod(factorial[n - 1], MOD - 2, MOD);
        for (int i = n - 2; i >= 0; i--)
        {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        // Step 4: Compute combinations for choosing k indices
        long long combination = 0;
        if (k <= n - 1)
        {
            combination = factorial[n - 1] * invFact[k] % MOD * invFact[n - 1 - k] % MOD;
        }

        // Step 5: Compute power of (m-1) for remaining positions
        long long power = 1;
        if (n - k - 1 >= 0)
        {
            power = powMod(m - 1, n - k - 1, MOD);
        }

        // Step 6: Calculate result by combining values
        long long result = combination * m % MOD;
        result = result * power % MOD;

        return (int) result;
    }

private:
    // Helper function for modular exponentiation
    long long powMod(long long x, long long y, long long mod)
    {
        long long res = 1;
        x %= mod;
        
        while (y > 0)
        {
            if (y & 1) res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        
        return res;
    }
};