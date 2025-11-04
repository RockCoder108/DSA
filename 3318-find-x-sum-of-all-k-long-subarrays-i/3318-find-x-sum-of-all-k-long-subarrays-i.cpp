class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;

            // Step 1: count frequency in window
            for (int j = i; j < i + k; j++)
                freq[nums[j]]++;

            // Step 2: convert to vector
            vector<pair<int, int>> arr;
            for (auto& p : freq)
                arr.push_back({p.first, p.second});

            // Step 3: sort by freq desc, value desc
            sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });

            // Step 4: compute x-sum
            int sum = 0;
            for (int j = 0; j < min(x, (int)arr.size()); j++)
                sum += arr[j].first * arr[j].second;

            ans.push_back(sum);
        }

        return ans;
    }
};