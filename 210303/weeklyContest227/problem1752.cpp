// Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
      int cnt = 0;
      vector<int> sorted;
      for(int i=0;i<nums.size();i++){
        sorted.push_back(nums[i]);
      }
      sort(sorted.begin(), sorted.end());
      for(int i=0;i<nums.size();i++){
        int cnt=0;
        for(int j=0;j<nums.size();j++){
          int idx = (i+j)%nums.size();
          if(nums[idx] != sorted[j]){
            break;
          }
          cnt++;
        }
        if(cnt == nums.size()) return true;
      }
      return false;
    }
};