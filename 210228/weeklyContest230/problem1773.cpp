// Count Items Matching a Rule
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> type, color, name;
      for(auto item : items){
        type[item[0]]++;
        color[item[1]]++;
        name[item[2]]++;
      }
      if(ruleKey == "color"){
        return color[ruleValue];
      }
      else if(ruleKey == "type"){
        return type[ruleValue];
      }
      else if(ruleKey == "name"){
        return name[ruleValue];
      }
      return 0;
    }
};