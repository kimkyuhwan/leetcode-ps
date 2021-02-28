// Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int l = 0;
        int r = height.size()-1;
        int maxx = 0;
        while(l<r){
          int val = (r-l) * min(height[l], height[r]);
          maxx = max(maxx, val);
          if(height[l] < height[r]) l++;
          else r--;
        }
        return maxx;
    }
};
