// Palindrome Partitioning IV
class Solution {
public:
    bool isPalindrome[2010][2010];
    string input;
    void setPalindrome(){
      int n = input.size();
      for(int i=0;i<n;i++){
        isPalindrome[i][i] = true;
      }
      for(int i=0;i<n-1;i++){
        if(input[i] == input[i+1])
        {
          isPalindrome[i][i+1] = true;
        }
      }
      for(int gap=2;gap<n;gap++){
        for(int f=0;f<n-gap;f++){
          int b = f+gap;
          if(input[f] == input[b] && isPalindrome[f+1][b-1]){
            isPalindrome[f][b]=true;
          }
        }
      }
    }
    
    bool checkPartitioning(string s) {
      int n = s.size();
      input = s;
      memset(isPalindrome, 0, sizeof(isPalindrome));
      setPalindrome();
      for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
          if(isPalindrome[0][i] && isPalindrome[i+1][j] && isPalindrome[j+1][n-1]){
            return true;
          }
        }
      } 
      return false;
    }
};