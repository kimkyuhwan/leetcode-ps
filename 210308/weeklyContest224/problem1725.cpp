// Number Of Rectangles That Can Form The Largest Square
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxx = 0;
        int ans = 0;
        for(int i=0;i<rectangles.size();i++){
          int a = rectangles[i][0];
          int b = rectangles[i][1];
          int val = min(a,b);
          if(val > maxx){
            ans = 1;
            maxx = val;
          }
          else if(val == maxx){
            ans++;
          }
        }
        return ans;
    }
};