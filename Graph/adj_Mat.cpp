#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n, m;
  cin>>n>>m;
  vector<vector<int>> arr(n+1,vector<int>(n+1,0));
  int i=0;
  while(m--){
    int d;
    int e;
    cin>>d>>e;
    arr[d][e]=1;
    arr[e][d]=1;
  }

  cout<<"adj matrix"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }

}