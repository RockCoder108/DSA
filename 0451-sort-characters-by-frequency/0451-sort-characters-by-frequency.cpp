class Solution {
public:
    string frequencySort(string s) {
        // reverse(s.begin(),s.end());
        // return s;
        // sort(s.begin(),s.end());
        // return s;
        // unordered_map<char,int> m;
        // for(char ch:s) m[ch]++;
        // sort(s.begin(),s.end());
        // return s;


        unordered_map<char,int> m;
        for(char ch:s) m[ch]++;
        vector<pair<int, char>> v;
        for(auto e: m) v.push_back({e.second,e.first});
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto e:v){
            int f =e.first;
            char ch=e.second;
            while(f--){
                ans+=ch;
            }
        }
        return ans;
    }
};