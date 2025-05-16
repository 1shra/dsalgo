#include<iostream>
#include<vector>
using namespace std;
int partition(int p,int t){
     vector<vector<int>> vec(t+1,vector<int>(p+1));
     for(int i=0;i<=p;i++){
        vec[0][i]=0;
     }
     for(int i=0;i<=t;i++){
        vec[i][0]=0;
     }
     for(int i=1;i<=t;i++){
        for(int j=1;j<=p;j++){
            if(i==1){
                vec[i][j]=1;
            }
            else if(j==i){
                vec[i][j]=1;
            }
            else if(j<i){
                vec[i][j]=0;
            }
            else{
                vec[i][j]=(vec[i][j-1]*i)+(vec[i-1][j-1]);
            }
        }  
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=p;j++){
            cout<<vec[i][j]<<" ";
        }  
        cout<<endl;
    }
    return vec[t][p];     
}
int main(){
    int p = 5;
    int t = 4;
    cout<<partition(p,t);
}