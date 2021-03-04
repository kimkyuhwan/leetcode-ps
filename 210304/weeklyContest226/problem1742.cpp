// Maximum Number of Balls in a Box
class Solution {
public:
    int getNumber(int n){
      int ret = 0;
      while(n){
        ret+= n%10;
        n/=10;
      }
      return ret;
    }
    int countBalls(int lowLimit, int highLimit) {
       int cnt[100010]={};
        int ans = 0;
        for(int i=lowLimit;i<=highLimit;i++){
          int val = getNumber(i);
          printf("%d\n",val);
          ans = max(ans, ++cnt[val]);
        }
        return ans;
    }
};