// Largest Merge Of Two Strings
class Solution {
public:

    
    string largestMerge(string word1, string word2) {
      int idx1=0, idx2=0;
      int n1 = word1.size();
      int n2 = word2.size();
      string merged;
      int cnt = 0;
      while(idx1 != n1 || idx2 != n2){
        if(idx1 == n1){
          merged += word2[idx2++];
        }
        else if(idx2 == n2){
          merged += word1[idx1++];
        }
        else{
          if(word1[idx1] == word2[idx2]){
            if(idx1+1 < n1 && idx2+1 < n2){
              merged += (word1[idx1+1] < word2[idx2+1]) ? word2[idx2++] : word1[idx1++];
              continue;
            }
          }
          if(cnt >=1){
            if(word1[idx1] == merged[cnt-1]){
              merged += word2[idx2++];
              continue;
            }
            else if(word2[idx2] == merged[cnt-1]){
              merged += word1[idx1++];
              continue;
            }
          }
          if(word1[idx1] < word2[idx2]){
            merged += word2[idx2++];
          }
          else{
            merged += word1[idx1++];
          }
        }

      }
      return merged;
    }
};