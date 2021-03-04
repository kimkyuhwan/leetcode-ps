class Solution {
public:
    string largestMerge(string word1, string word2) {
      int idx1=0, idx2=0;
      int n1 = word1.size();
      int n2 = word2.size();
      string merged;
      while(idx1 != n1 && idx2 != n2){
        if(idx1 == n1){
          merged += word2[idx2++];
        }
        else if(idx2 == n2){
          merged += word1[idx1++];
        }
        else{
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