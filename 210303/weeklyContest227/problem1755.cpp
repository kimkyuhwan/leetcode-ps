// Closest Subsequence Sum
class Solution {

public:
    vector<int> makeWholeComb(vector<int> &nums){
      vector<int> ret;
      int last = (1 << nums.size());
      for(int i=0;i<last;i++){
        int sum = 0;
        for(int j=0;j<nums.size();j++){
          if((i & (1<<j)) != 0 ){
            sum += nums[j];
          }
        }
        ret.push_back(sum);
      }
      sort(ret.begin(), ret.end());
      return ret;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
      vector<int> a, b;
      int mid = nums.size()/2;
      for(int i=0;i<nums.size();i++){
        if(i < mid) a.push_back(nums[i]);
        else b.push_back(nums[i]);
      }
      a = makeWholeComb(a);
      b = makeWholeComb(b);
      int ans = 2100000000;
      for(auto val : a){
        auto lb = lower_bound(b.begin(), b.end(), goal-val);
        auto ub = upper_bound(b.begin(), b.end(), goal-val);
        int ll = lb - b.begin();
        int uu = ub - b.begin();
        if(ll == b.size()) ll--;
        if(uu == b.size()) uu--;
        int minn = min(abs(goal-(val+b[ll])), abs(goal-(val+b[uu])));
        ans = min(minn, ans);
      }
      return ans;
    }
};