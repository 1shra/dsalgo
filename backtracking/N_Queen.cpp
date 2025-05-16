#include<iostream>
#include<vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board,int row,int col,int N){
  for(int i=0;i<row;i++){
    if(board[i][col]==1){
      return false;
    }
  }
  for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
    if(board[i][j]==1) return false;
  }
  for(int i=row-1,j=col+1;i>=0&&j>=0;i--,j++){
    if(board[i][j]==1) return false;
  }
  return true;
}
bool solve(vector<vector<int>>& board, int row, int N){
  if(row == N){
    return true;
  }
  for(int col=0;col<N;col++){
    if(isSafe(board,row,col,N)){
      board[row][col]=1;
      if(solve(board,row+1,N)){
        return true;
      }
      board[row][col]=0;
    }
  }
  return false;
}

 void printboard(const vector<vector<int>>& board, int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(board[i][j]==1){
        cout<<"Q ";
      }
      else{
        cout<<". ";
      }
    }
    cout<<endl;
  }
 }


int main(){
  vector<vector<int>>  board(8,vector<int>(8,0));
  if(solve(board,0,8)){
    cout<<"sol"<<endl;
    printboard(board,8);
  }
  else{
    cout<<"No soln exits "<<8<<endl;
  }
  return 0;
}