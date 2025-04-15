class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next_greater;
        stack<int> s;
        vector<int> v;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && nums2[i]>s.top()){
                next_greater[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            next_greater[s.top()] = -1;
            s.pop();
        }
        for (int num : nums1) {
            v.push_back(next_greater[num]);
        }
        return v;
    }
};