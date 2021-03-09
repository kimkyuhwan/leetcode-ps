// Minimize Hamming Distance After Swap Operations
class Solution {
public:

    void dfs(vector<bool> &visited, vector<vector<int> >&edges, int cur, vector<int> &group){
      if(visited[cur]) return;
      group.push_back(cur);
      visited[cur] = true;
      for(int next : edges[cur]){
        dfs(visited, edges, next, group);
      }
    }

    int countSameElements(vector<int> &group, vector<int>& source, vector<int>& target){
      int same = 0;
      unordered_map<int, int> count;

      for(int i : group){
        if (count[source[i]] < 0) same++;
        count[source[i]]++;

        if (count[target[i]] > 0) same++;
        count[target[i]]--;
      }
      return same;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      int n = source.size();
      vector<vector<int> > edges;
      edges.resize(n);
      vector<bool> visited;
      visited.resize(n);
      for(auto v : allowedSwaps){
        int a = v[0];
        int b = v[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
      }
      int same = 0;
      for(int i=0;i<n;i++){
        if(edges[i].size() == 0){
          if(target[i] == source[i]){
            same +=1;
            continue;
          }
        }
        if(visited[i]) continue;
        vector<int> group;
        dfs(visited, edges, i, group);
        same += countSameElements(group, source, target);
      }

      return n - same;
    }
};