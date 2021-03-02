// Minimum Limit of Balls in a Bag
typedef long long ll;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
      int avg = 0;
      int ans = 0;
      ll total = 0;
      for(int i=0;i<nums.size();i++){
        total += nums[i];
      }
      int n = nums.size() + maxOperations;
      avg = total/n;
      priority_queue<int> pq;
      for(int i=0;i<nums.size();i++){
        maxOperations -= nums[i]/avg;
        if(avg > nums[i]){
            continue;
        }
        else{
            
        }
        pq.push(nums[i]%avg);
      }
      for(int i=0;i<maxOperations;i++){
        if(pq.empty()){
          break;
        }
        else{
          pq.pop();
        }
      }
      if(!pq.empty()) ans = avg+pq.top();
      else ans = avg;
      return ans;
    }
};