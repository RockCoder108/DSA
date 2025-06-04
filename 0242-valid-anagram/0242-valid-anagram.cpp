class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(const auto  &el:s) {
            m1[el]++;
        }
        for(const auto  &el:t) {
            m2[el]++;
        }
        return m1==m2;

    }
};