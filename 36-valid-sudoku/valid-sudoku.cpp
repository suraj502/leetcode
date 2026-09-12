class Solution {
public:
bool possible(int row, int col, char ch,vector<vector<char>>& board){
    // to check row 
    for(int i=0;i<9;i++){
       if(i != col && board[row][i] == ch)
                return false;
    }
    // check col
     for(int i=0;i<9;i++){
        if(i !=row && board[i][col]==ch)return false;
    }
    // check 3*3
      int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);
       for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                int r = boxRowStart + i;
                int c = boxColStart + j;

                if((r != row || c != col) && board[r][c] == ch)
                    return false;
            }
        }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch!='.'){
                if(possible(i,j,ch,board)==false){
                   return false;
                }
            }
            }
        }
        return true;
    }
};