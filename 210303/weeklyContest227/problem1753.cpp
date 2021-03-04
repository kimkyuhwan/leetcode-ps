// Maximum Score From Removing Stones
class Solution {
public:
    int maximumScore(int a, int b, int c) {
      vector<int> nums;
      int ans = 0;
      nums.push_back(a);
      nums.push_back(b);
      nums.push_back(c);
      sort(nums.begin(), nums.end());
      if(nums[2] >= nums[0]+nums[1]){
        nums[2] -= (nums[0]+nums[1]);
        ans = (nums[0]+nums[1]);
      }
      else{
        ans = (a+b+c)/2;
      }
      return ans;
    }
};