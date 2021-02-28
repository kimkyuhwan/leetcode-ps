// Palindrome Number
class Solution {
public:
    bool isPalindrome(string &s, int src, int dst){
        if(src == dst || src > dst) return true;
        if(s[src] == s[dst]) return isPalindrome(s, src+1, dst-1);
        return false;
    }
    
    bool isPalindrome(string s){
        return isPalindrome(s, 0, s.size()-1);
    }
    
    bool isPalindrome(int x) {
        string s = to_string(x);
        return isPalindrome(s);
    }
};