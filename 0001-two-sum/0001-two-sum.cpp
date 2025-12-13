class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        unordered_map<int, int> h;
        vector<int> ans;
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            int need = t-arr[i];

            if(h.find(need)!=h.end()){
                ans.push_back(h[need]);
                ans.push_back(i);
                return ans;
            }

            h[arr[i]] = i;
        }
        return ans;
    }
};

//h.push_back(t-arr[0],0);