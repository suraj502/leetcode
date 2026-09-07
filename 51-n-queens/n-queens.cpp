class Solution {
public:
void solve(int col, vector<string>&board,int n,vector<int>&leftrow,vector<int>&lowerdig,vector<int>&upperdig,vector<vector<string>>&ans){
if(col==n){
    ans.push_back(board);
    return ;
}
  for(int row=0;row<n;row++){
    if(leftrow[row]==0 && lowerdig[row+col]==0 &&upperdig[n-1+col-row]==0){
        leftrow[row]=1;
        lowerdig[row+col]=1;
        upperdig[n-1+col-row]=1;
        board[row][col]='Q';
        solve(col+1,board,n,leftrow,lowerdig,upperdig,ans);
         board[row][col]='.';
          leftrow[row]=0;
        lowerdig[row+col]=0;
        upperdig[n-1+col-row]=0;
    }
  }

}

    vector<vector<string>> solveNQueens(int n) {
vector<vector<string>>ans;
vector<string>board(n,string(n,'.'));
vector<int>leftrow(n,0); vector<int>lowerdig(2 * n - 1, 0),upperdig(2 * n - 1, 0);
solve(0,board,n,leftrow,lowerdig,upperdig,ans);
  return ans;
    }
};