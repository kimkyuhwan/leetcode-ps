// Longest Palindromic Substring
class Solution {
public:
    int dp[1010][1010];
    int parent[1010][1010];
    string input;
    int maxLength = 1;
    int maxA = 0;
    int maxB = 0;
    int solution(int a, int b){
        int &ret = dp[a][b];
        if(ret!=-1) return ret;
        if(a == b) return ret = 1;
        if(a > b) return ret = 1;
        ret = 0;
        if(input[a] == input[b]){
            ret = solution(a+1, b-1);
            if(ret == 1){
                int length = (b-a+1);
                if(maxLength < length){
                    maxA = a;
                    maxB = b;
                    maxLength = length;
                }
            }
        }
        return ret;
    }
    
    
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        input = s;
        maxLength = 1;
        maxA = 0;
        maxB = 0;
        for(int a=0;a<s.size();a++){
            for(int b=a;b<s.size();b++){
                if(s[a] == s[b]){
                    solution(a,b);
                }
            }
        }
        string ans;
        for(int i=maxA;i<=maxB;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};