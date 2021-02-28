// Closest Dessert Cost
class Solution {
public:


    int getAnswer(int limit, int realValue, int nextValue){
      if(abs(limit-realValue) == abs(limit-nextValue)){
        return (realValue < nextValue) ? realValue : nextValue;
      }
      return abs(limit-realValue) >= abs(limit-nextValue) ? nextValue : realValue;
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = 1000000000;
        for(int i=0;i<baseCosts.size();i++){
          int base = baseCosts[i];
          ans = getAnswer(target, ans, base);
          vector<int> costArray;

          costArray.resize(toppingCosts.size());
          int maxA=1;
          for(int k=0;k<toppingCosts.size();k++){
            maxA*=3;
          }
          for(int k=0;k<maxA;k++){
            int value = k;
            for(int j=0;j<toppingCosts.size();j++){
              costArray[j] = value%3;
              value/=3;
            }
            
            int totalToppingCost = 0;
            for(int i=0;i<toppingCosts.size();i++){
              totalToppingCost += toppingCosts[i] * costArray[i];
            }
             int totalCost = base + totalToppingCost;
            ans = getAnswer(target, ans, totalCost);
          }
        }          
        return ans;
    }
};