// Largest Submatrix With Rearrangements
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        unordered_map<int, multiset<int>> mp;
        
        for(auto mat : matrix){
          ans = max(ans, accumulate(mat.begin(), mat.end(), 0));
        }

        int C = matrix[0].size();
        int R = matrix.size();
        for(int i=0;i<C;i++){
          int cnt = 0;
          for(int j=0;j<R;j++){
            if(matrix[j][i] == 0){
              cnt = 0;
            }
            else{
              cnt++;
              mp[j].insert(cnt);
            }
          }
        }
        for(auto [key, vec] : mp){
          int l = vec.size();
          for(auto x : vec){
            ans = max(ans, x * l);
            l--;
          }

        }
        return ans;
    }
};
