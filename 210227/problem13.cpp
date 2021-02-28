// Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'M'){
                ret += 1000;
            }
            else if(s[i] == 'C'){
                ret += 100;
                if(i+1 < s.size()){
                    if(s[i+1] == 'M') {
                        ret+= 800; // 900 - 100
                        i++;
                    }
                    else if(s[i+1] == 'D') {
                        ret+=300; // 400 - 100
                        i++;
                    }
                }
            }
            else if(s[i] == 'D'){
                ret += 500;
            }
            else if(s[i] =='X'){
                ret += 10;
                if(i+1 < s.size()){
                    if(s[i+1] == 'C') {
                        ret+= 80; // 90 - 10
                        i++;
                    }
                    else if(s[i+1] == 'L') {
                        ret+=30; // 40 - 10
                        i++;
                    }
                }
            }
            else if(s[i] == 'L'){
                ret += 50;
            }
            else if(s[i] == 'I'){
                ret += 1;
                if(i+1 < s.size()){
                    if(s[i+1] == 'X') {
                        ret+= 8; // 9 - 1
                        i++;
                    }
                    else if(s[i+1] == 'V'){
                        ret+=3; // 4 - 1
                        i++;
                    }
                }
            }
            else if(s[i] == 'V'){
                ret += 5;
            }
        }
        return ret;
    }
};