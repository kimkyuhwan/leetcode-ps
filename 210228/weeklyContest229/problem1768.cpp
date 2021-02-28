class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string merged;
      int sz = min(word1.size(),word2.size());
      for(int i=0;i<sz;i++){
        merged += word1[i];
        merged += word2[i];
      }
      for(int i=sz;i<word1.size();i++) merged += word1[i];
      for(int i=sz;i<word2.size();i++) merged += word2[i];
      return merged;
    }
};