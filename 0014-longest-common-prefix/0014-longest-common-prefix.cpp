class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans="";
        int n=s.size();
        sort(s.begin(),s.end());
        string s1=s[0],s2=s[n-1];
        for(int i=0;i<min(s1.length(),s2.length());i++){
            if(s1[i]!=s2[i]){
                return ans;
            }
            ans+=s1[i];
        }
        return ans;
    }
};