// Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charNum[255]={};
        int lastIndex[255]={};
        int maxLength = 0;
        int currentLength = 0;
        int fr = 0;
        for(int pos=0;pos<s.size();pos++){
            int asciiIndex = s[pos];
            if(charNum[asciiIndex] > 0){
                for(int i = fr;i<=lastIndex[asciiIndex];i++){
                    int asciiIndex = s[i];
                    charNum[asciiIndex]--;
                }
                currentLength -= (lastIndex[asciiIndex] - fr + 1);
                fr = lastIndex[asciiIndex]+1;
            }
            currentLength += 1;   
            charNum[asciiIndex]++;
           
            lastIndex[asciiIndex] = pos;
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};