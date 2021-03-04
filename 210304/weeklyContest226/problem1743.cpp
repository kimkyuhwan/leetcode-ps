// Restore the Array From Adjacent Pairs
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int> > adj;
        for(int i=0;i<adjacentPairs.size();i++){
          int a = adjacentPairs[i][0];
          int b  = adjacentPairs[i][1];
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
        for(auto m : adj){
          if(m->second.size() == 1){
            int start = m->first;
            break;
          }
        }
        map<int, bool> visited;
        int idx = start;
        vector<int> ans;
        ans.push_back(idx);
        visited[idx]  = true;
        for(int i=0;i<adjacentPairs.size();i++){
          for(int j=0;j<adj[idx].size();j++){
            int there = adj[idx][j];
            if(visited[there]) continue;
            visited[there] = true;
            ans.push_back(there);
            idx = there;
            break;
          }
        }
        return ans;
    }
};