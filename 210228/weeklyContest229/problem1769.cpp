// Minimum Number of Operations to Move All Balls to Each Box
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i=0;i<boxes.size();i++){
          int value = 0;
          for(int j=0;j<boxes.size();j++){
            if(i==j) continue;
            if(boxes[j]=='1'){
              value += abs(i-j);
            }
          }
          ans.push_back(value);
        }
        return ans;
    }
};