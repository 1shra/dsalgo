/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int longest_substring(int k,const string &arr){
    unordered_map<char,int> substring;
    int window_start=0,window_end = 0;
    int maxlen = 0;
    for (window_end = 0; window_end < arr.size(); window_end++)
    {
        char s;
        s = arr[window_end];
        substring[s]++;
        while(substring.size()>k)
        {
            char a; 
            a = arr[window_start];
            substring[a]--;
            if(substring[a]==0){
                substring.erase(a);
            }
            window_start++;
        }
        maxlen=max(maxlen,window_end-window_start+1);
    }
    return maxlen;
}


int main(){
    cout<<"The longest substring with no more than "<<longest_substring(2,"aacai");
    return 0;
}