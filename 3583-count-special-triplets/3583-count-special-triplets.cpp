class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1'000'000'007;
        int n = nums.size();

        unordered_map<long long, long long> leftFreq, rightFreq;

        // Build right frequency map
        for (int x : nums) {
            rightFreq[x]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long val = nums[j];
            rightFreq[val]--;  // this element is no longer on the right side

            long long target = 2LL * val;

            long long left = leftFreq[target];
            long long right = rightFreq[target];

            ans = (ans + (left * right) % MOD) % MOD;

            leftFreq[val]++;  // move nums[j] to the left side
        }

        return (int)ans;
    }
};