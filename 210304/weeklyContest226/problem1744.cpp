// Can You Eat Your Favorite Candy on Your Favorite Day?
typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
      vector<bool> ans;
      vector<ll> psumCandy;
      psumCandy.resize(candiesCount.size()+1);
      for(int i=1;i<psumCandy.size();i++){
        psumCandy[i] = candiesCount[i-1]+psumCandy[i-1];
      }

      for(int i=0;i<queries.size();i++){
        int favType = queries[i][0];
        int favDay = queries[i][1];
        int dailyCap = queries[i][2];
        ll value = psumCandy[favType];
        ll value2 = psumCandy[favType+1];
        ll max_eating= (ll)(favDay+1) * (ll)dailyCap;
        ll min_eating= favDay;
        if(min_eating > value2){
          ans.push_back(false);  
        }
        else if(max_eating <= value2){
          ans.push_back(false);
        }
        else ans.push_back(true);
      }
      return ans;
    }
};