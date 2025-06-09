class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> v;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<nums[i+1] || nums[i]<nums[i-1]){
        //         int a=max(nums[i+1],nums[i-1]);
        //         v.push_back(a);
        //     }else{
        //         v.push_back(-1);
        //     }
        // }
        // return v;

        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i%n] )
                ans[st.top()] = nums[i % n], st.pop();
            if (i < n) {
                st.push(i);
            }
        }
        return ans;

        //     int n = nums.size();
        //     vector<int> v;
        //     for (int i = 0; i < n; i++) {
        //         int next = nums[(i + 1) % n];
        //         int prev = nums[(i - 1 + n) % n];
        //         if (nums[i] < next || nums[i] < prev) {
        //             int a = max(next, prev);
        //             v.push_back(a);
        //         } else {
        //             v.push_back(-1);
        //         }
        //     }
        //     if(nums[0]<nums[1]){
        //         v[0]=nums[1];
        //     }
        //     return v;
    }

    // stack<int> st;
};