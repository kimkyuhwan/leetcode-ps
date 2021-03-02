class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
          if(s == ('0'+cnt)){
            ans++;
          }
          cnt++;
          cnt%=2;
        }
        ans = min(ans, s.size()-ans);
        return ans;
    }
};