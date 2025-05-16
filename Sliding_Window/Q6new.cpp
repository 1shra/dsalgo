#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longstr(int k,const string &str){
    int maxrepeaterchar=0, window_start = 0, maxchar = 0;
    unordered_map<char,int> ch;
    cout<<str.size()<<endl;
    for(int window_end = 0 ; window_end < str.size();window_end++){
        char s;
        s = str[window_end];
        ch[s]++;
        maxrepeaterchar = max(maxrepeaterchar,ch[s]);
        
        if(window_end-window_start+1-maxrepeaterchar>k){
            char a;
            a = str[window_start];
            ch[a]--;
            window_start++;
        }
        maxchar=max(maxchar,window_end-window_start+1);
    }
    return maxchar;
}

int main(){
    cout<<"Longest substring with distinct character: "<<longstr(2,"baabbbaaaa");
    return 0;
}