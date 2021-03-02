// Count Number of Homogenous Substrings
class Solution {
public:
    int psum[100010];
    int MOD = 1000000007;
    int countHomogenous(string s) {
        for(int i=1;i<=s.size();i++){
          psum[i] = psum[i-1]+i;
          psum[i]%=MOD;
        }
        int cnt=1;
        int ans=0;
        char prevChar = s[0];
        for(int i=1;i<=s.size();i++){
          if(i == s.size()) {
            ans+=psum[cnt];
            ans%=MOD;  
          }
          else if(prevChar == s[i]){
            cnt++;
          }
          else{
            ans+=psum[cnt];
            ans%=MOD;
            cnt=1;
            prevChar = s[i];
          }
        }
        return ans;
    }
};