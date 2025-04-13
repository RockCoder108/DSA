class Solution {
public:
    int checkpar(char s2,char s3){
        if((s2=='(' && s3==')')||(s2=='{' && s3=='}')||(s2=='['&&s3==']')){
            return 0;
        }else{
            return -1;
        }
    }
    bool isValid(string s) {
        stack<char> s1;
        int len = s.size();
        int val=INT_MIN;
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                s1.push(s[i]);
            }else{
                if(s1.empty()) return false;
                val=checkpar(s1.top(),s[i]);
            }
            if(val==0){
                s1.pop();
                val=INT_MIN;
            }else if(val==-1){
                return false;
            }
        }
        return true;
    }
};