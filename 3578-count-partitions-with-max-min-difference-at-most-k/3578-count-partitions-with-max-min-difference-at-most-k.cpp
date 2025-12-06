class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();

        vector<long long> dp(n + 1, 0);   // dp[0] corresponds to empty prefix
        vector<long long> pref(n + 1, 0); // prefix sums of dp
        dp[0] = 1;
        pref[0] = 1;

        deque<int> maxD, minD;
        int left = 0;

        for (int i = 0; i < n; i++) {

            // Maintain max deque
            while (!maxD.empty() && nums[maxD.back()] <= nums[i])
                maxD.pop_back();
            maxD.push_back(i);

            // Maintain min deque
            while (!minD.empty() && nums[minD.back()] >= nums[i])
                minD.pop_back();
            minD.push_back(i);

            // Shrink left boundary while window invalid
            while (!maxD.empty() && !minD.empty() &&
                   nums[maxD.front()] - nums[minD.front()] > k) {

                if (maxD.front() == left)
                    maxD.pop_front();
                if (minD.front() == left)
                    minD.pop_front();
                left++;
            }

            // Now all segments starting from left..i are valid.
            // dp[i+1] is sum of dp[left]...dp[i]
            long long ways = pref[i] - (left > 0 ? pref[left - 1] : 0);
            ways = (ways % MOD + MOD) % MOD;

            dp[i + 1] = ways;
            pref[i + 1] = (pref[i] + dp[i + 1]) % MOD;
        }

        return dp[n];
    }
};