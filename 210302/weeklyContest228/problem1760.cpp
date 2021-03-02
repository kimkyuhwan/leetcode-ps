#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
      int avg = 0;
      ll total = 0;
      for(int i=0;i<nums.size();i++){
        total += nums[i];
      }
      int n = nums.size() + maxOperations;
      avg = total/n;
      priority_queue<int> pq;
      for(int i=0;i<nums.size();i++){
        n -= nums[i]/avg;
        pq.push(nums[i]%avg);
      }
      for(int i=0;i<n;i++){
        if(pq.empty()){
          break;
        }
        else{
          pq.pop();
        }
      }
      if(!pq.empty()) ans = pq.top();
      else ans = avg;
      return ans;
    }
};

vector<int> a;
int main(){
  Solution sol;
  a.push_back(7);
    a.push_back(17);
  cout<<sol.minimumSize(a, 2);
}