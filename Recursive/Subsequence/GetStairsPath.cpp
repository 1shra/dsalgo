#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> stairPath(int n){
    if(n==0){
      vector<string> bus = {};
      return bus;
    }


    vector<string> path1=stairPath(n-1);
    vector<string> path2=stairPath(n-2);
    vector<string> path3=stairPath(n-3);

    for(String path: paths1){
      paths.push_back(1+path);
    }
    for(String path: paths2){
      paths.push_back(2+path);
    }
    for(String path: paths3){
      paths.push_back(3+path);
    }

    return paths;
}


int main(){
    int noStairs = 5;
    vector<int>  result = stairPath(noStairs);
    for(int i=0;i<result.size();i++){
        cout<<"["<<result[i]<<"]";
    }
    return 0;
}