class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool rows[9][9]= {false};
       bool cols[9][9]= {false};
bool box[9][9]={false};
for(int r=0; r<9;r++){
    for(int c=0; c<9;c++){
        if(board[r][c]=='.')continue;
        int num= board[r][c]-'1';
        int boxindex=(r/3)*3+(c/3);
        if(rows[r][num]|| cols[c][num]|| box[boxindex][num])
        return false;

        rows[r][num]=true;
        cols[c][num]=true;
       box[boxindex][num] = true;
            }
        }
        
        return true;
    }
};
