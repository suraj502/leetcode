class Solution {
public:
bool find(vector<vector<char>>& board, string word,int i, int j, int ind){
  if(ind==word.size())return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind]) {
            return false;
        }
        if(board[i][j]=='#')return false;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        int temp=board[i][j];
        board[i][j]='#';
         for (int k = 0; k < 4; k++) {
            int row = i + nrow[k];
            int col = j + ncol[k];

            if (find(board, word, row, col, ind + 1))
                return true;
        }
   board[i][j]=temp;
   return false;
}

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&& find(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};