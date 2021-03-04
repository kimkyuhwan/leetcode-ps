class Solution {
public:
    bool check(vector<int>& nums) {
      int cnt = 0;
      for(int i=0;i<nums.size();i++){
        if(nums[i] > nums[i+1]) cnt++;
      }
      if(cnt > 2) return false;
      return true;
    }
};