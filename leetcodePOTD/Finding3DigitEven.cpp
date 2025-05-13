#include<iostream>
#include<vector>
using namespace std;



vector<int> findEvenNumbers(vector<int>& digits) {
  vector<int> count(10,0);
  for(int i=0;i<digits.size();i++){
      count[digits[i]]++;
  }
  vector<int>ans;
  for(int i=1;i<=9;i++){
      for(int j=0;j<=9;j++){
          for(int k=0;k<=8;k+=2){
              if((count[i]>0 && count[j]>(j==i))&&count[k]>(k==i)+(k==j)){
                  ans.push_back((i*100)+(j*10)+k);
              }
          }
      }
  }
  return ans;
}

int main(){
  vector<int> nums = {2,1,3,0};
  vector<int> vec = findEvenNumbers(nums);
  for(int i:vec){
    cout<<i<<" ";
  }
  cout<<endl;
}