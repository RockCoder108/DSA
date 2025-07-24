class Solution {
public:
    void solve(vector<int>& arr, int ind,vector<vector<int>>&v){
        if(ind==arr.size()){
            v.push_back(arr);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            swap(arr[ind],arr[i]);

            solve(arr,ind+1,v);

            swap(arr[ind],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>>v;
        solve(arr,0,v);
        return v;
    }
};