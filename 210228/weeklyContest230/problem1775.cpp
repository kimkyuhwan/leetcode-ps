#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int cnt1[7]={};
        int cnt2[7]={};
        int ans = 0;
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<nums1.size();i++){
          cnt1[nums1[i]]++;
          sum1+= nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
          cnt2[nums2[i]]++;
          sum2+= nums2[i];
        }
        printf("sum 1 = %d\n ",sum1);
        printf("sum 2 = %d\n",sum2);
        if(sum1 == sum2) return ans;
        int val = abs(sum2-sum1);
        int minus[6]={};
        int plus[6]={};
        if(sum1 < sum2){          
          for(int i=5;i>=1;i--){
            minus[i] = cnt1[6-i] +cnt2[i+1];
          }
        }
        else{
          for(int i=5;i>=1;i--){
            minus[i] = cnt1[i+1] +cnt2[6-i];
          }
        } // 11, 1
        for(int i=5;i>=1;i--){
            if(val >= i){
              int needs = val/i;
              int cost = min(needs, minus[i]);
              val -= (i * cost);
              ans += cost;
            }
            if(val>0 && val <= i && minus[i]){
              ans++;
              val = 0;
              break;
            }
          }
        if(val != 0 ) return -1;
        return ans;
    }
};

int main(){
  vector<int> a;
  a.push_back(5);
  a.push_back(2);
  a.push_back(1);
  a.push_back(5);
  a.push_back(2);
  a.push_back(2);
  a.push_back(2);
  a.push_back(2);
  a.push_back(4);
  a.push_back(3);
  a.push_back(3);
  a.push_back(5);
  vector<int> b;
  b.push_back(1);
  b.push_back(4);
  b.push_back(5);
  b.push_back(5);
  b.push_back(6);
  b.push_back(3);
  b.push_back(1);
  b.push_back(3);
  b.push_back(3);

  Solution sol;
  cout<<sol.minOperations(a,b);

} 