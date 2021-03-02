typedef long long ll;
class Solution {
public:

    int isPossible(vector<int> nums, int n, int minValue){
      for(int i=0;i<nums.size();i++){
        int cnt = nums[i]/minValue;
        if(nums[i]%minValue != 0){
          cnt++;
        }
        n -= cnt;
      }
      return n >= 0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
      int n = nums.size() + maxOperations;
      int l = 1;
      int r = 1000000000;
      while(l<r){
        int mid = (l+r)>>1;
        if(isPossible(nums, n, mid)){
          r = mid;
        }
        else{
          l = mid+1;
        }
      }
      int ans = l;
      return ans;
    }
};