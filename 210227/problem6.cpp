// ZigZag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        vector<vector<int> > table;
        table.resize(numRows);

        if(numRows == 1){
          return s;
        }
        bool goingDown = true;
        int tableIndex = 0;
        for(int i=0;i<s.size();i++){
          table[tableIndex].push_back(s[i]);
          tableIndex += (goingDown) ? 1 : -1;
          if(tableIndex == 0 || tableIndex == numRows-1) goingDown = !goingDown;
        }

        for(int i=0;i<numRows;i++){
          for(int j=0;j<table[i].size();j++)
            ret+=table[i][j];
        }

        return ret;
    }
};