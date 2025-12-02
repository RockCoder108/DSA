class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq;

        // Count points per y-coordinate
        for (auto &p : points) {
            freq[p[1]]++;
        }

        long long sumS = 0;     // sum of S_i
        long long sumS2 = 0;    // sum of S_i^2

        for (auto &kv : freq) {
            long long n = kv.second;
            if (n >= 2) {
                long long S = (n * (n - 1) / 2) % MOD;
                sumS = (sumS + S) % MOD;
                sumS2 = (sumS2 + (S * S) % MOD) % MOD;
            }
        }

        // Answer = ((sumS^2 - sumS2) / 2) % MOD
        long long ans = ( (sumS * sumS) % MOD - sumS2 + MOD ) % MOD;
        
        // divide by 2 under modulo: multiply by modular inverse of 2
        long long inv2 = (MOD + 1) / 2; // since MOD is prime
        ans = (ans * inv2) % MOD;

        return ans;
    }
};
