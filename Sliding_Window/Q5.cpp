#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longstr(const string &stri){
    int window_start=0;
    int k = 0;
    int a = 0;
    unordered_map<char,int> uniquechar;
    for(int window_end = 0 ; window_end < stri.size();window_end++){
        char s;
        s = stri[window_end];
        uniquechar[s]++;
        k=window_end-window_start+1;

        if(uniquechar.size()==k){
            a = max(a,k);
        }
        else{
            char z;
            z=stri[window_start];
            uniquechar[z]--;
            if(uniquechar[z]==0){
                uniquechar.erase(z);
            }
            window_start++;
        }
        
    }
    return a;
}

int main(){
    cout<<"Longest substring with distinct character: "<<longstr("pwwkew");
    return 0;
}