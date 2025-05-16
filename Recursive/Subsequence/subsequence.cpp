#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> subsequence(string str){
    if(str.size()==0){
        vector<string> result;
        result.push_back(" ");
        return result;
    }
    char c = str[0];
    string ros = str.substr(1);
    vector<string> res = subsequence(ros);

    vector<string> mystr;
    for(string re : res){
        mystr.push_back(""+re);
        mystr.push_back(c+ re);
    }
    
    return mystr;
}


int main(){
    string inputstring = "abc";
    vector<string>  result = subsequence(inputstring);
    for(int i=0;i<result.size();i++){
        cout<<"["<<result[i]<<"]";
    }
    return 0;
}