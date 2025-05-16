#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vect1{2,2,2,11};
    int j=1,i=0;
    while(j<vect1.size()){
        if(vect1[i]==vect1[j]){
            vect1.erase(vect1.begin()+j);
        }
        else{
            i++;
            j++;
        }
    }
    for(int k=0;k<vect1.size();k++){
        cout<<vect1[k]<<" ";
    }
    return 0;
}