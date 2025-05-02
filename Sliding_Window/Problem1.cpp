#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
bool permut_comb(const string &str,const string &pattern){
    unordered_map<char,int> charfrequencymp;
    int windowstart =0, matched = 0;
    for(auto it : pattern){
        charfrequencymp[it]++;
    }
    
    for(int windowend =0 ; windowend < str.length(); windowend++){
        char rightchar = str[windowend];
        if(charfrequencymp.find(rightchar) != charfrequencymp.end()){
            charfrequencymp[rightchar]--;
            if(charfrequencymp[rightchar]==0){
                matched++;
            }
        }
        if(matched== (int)charfrequencymp.size()){
            return true;
        }
        if(windowend >= pattern.length()-1){
            char leftchar = str[windowstart];
            if(charfrequencymp.find(leftchar)!=charfrequencymp.end()){
                if(charfrequencymp[leftchar] == 0){
                    matched--;
                }
                charfrequencymp[leftchar]++;
            }
        }

    }
    return false;
}




int main(){
    cout<<"String contain any permutation combination : "<<permut_comb("oidbcaf","idbc");
}