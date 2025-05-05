/*
1007. Minimum Domino Rotations For Equal Row
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/




#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;





int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
  int ans = INT_MAX;
  for(int i=1;i<=6;i++){
      int tpswap = 0;
      int btswap = 0;
      int flag=1;
      for(int j=0;j<tops.size();j++){
          if(tops[j]==i||bottoms[j]==i){
              if(tops[j]==i&&bottoms[j]==i){
                  continue;
              }
              else if(tops[j]==i){
                  btswap++;
              }
              else{
                  tpswap++;
              }
          }
          else{
              flag=0;
              break;
          }
      }
      if(flag){
          tpswap = min(tpswap,btswap);
          ans= (ans,tpswap);
      }
  }
  if(ans==INT_MAX){
      return -1;
  }
  return ans;
}

int main(){
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};
    cout<<minDominoRotations(tops,bottoms);
    return 0;
}