class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (long long x : batteries)
            sum += x;

        long long low = 0, high = sum / n, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long total = 0;
            for (long long x : batteries)
                total += min(x, mid);

            if (total >= mid * n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};