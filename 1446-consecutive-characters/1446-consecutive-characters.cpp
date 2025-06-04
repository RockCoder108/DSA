class Solution {
public:
    int maxPower(string s) {
        int ans=0,count=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }else{
                count=0;
            }
            ans=max(ans,count);
        }
        return ans+1;
    }
};