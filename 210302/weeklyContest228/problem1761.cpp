// Minimum Degree of a Connected Trio in a Graph
class Solution {
public:
    int init_value = 1000000000;
    int adj[410][410];
    int cnt[410];
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
          int a = edges[i][0];
          int b = edges[i][1];
          adj[a][b] = adj[b][a] = 1;
          cnt[a]++;
          cnt[b]++;
        }
        int ans = init_value;
        for(int i=1;i<=n;i++){
          for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
              if(adj[i][j] && adj[j][k] && adj[k][i]){
                int degree = cnt[i]+cnt[j]+cnt[k]-6;
                ans = min(ans, degree);
              }
            }
          }
        }
        if(ans == init_value) return -1;
        return ans;
    }
};