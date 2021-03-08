// Tuple with Same Product
class Solution {
public:
    map<int,int> muls;
    int tupleSameProduct(vector<int>& nums) {
         // 2개 고를 경우 (1000*99
        int ans = 0;
        for(int i=0;i<nums.size();i++){
          for(int j=i+1;j<nums.size();j++){
            int mul = nums[i] * nums[j];
            muls[mul]++;
          }
        }
        for(auto val = muls.begin();val!=muls.end();val++){
          int n  = val->second;
          ans += (n * (n-1)) / 2;
        }
        
        return ans * 8;
    }
};