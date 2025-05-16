#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int max_fruits(const vector<char>& vec){
    int k = 2;
    unordered_map<char,int> fruits_basket;
    int window_start = 0 , window_end = 0;
    int max_fruits = 0;
    for(window_end = 0; window_end<vec.size() ; window_end++){
        char s;
        s = vec[window_end];
        fruits_basket[s]++;
        while(fruits_basket.size() > k){
            char a;
            a = vec[window_start];
            fruits_basket[a]--;
            if(fruits_basket[a]==0){
                fruits_basket.erase(a);
            }
            window_start++;
        }
        max_fruits=max(max_fruits,window_end-window_start+1);
    }
    return max_fruits;
}  
int main(){
    cout<<"The maximum number of fruits in both the basket: "<<max_fruits(vector<char>{'A', 'B', 'C', 'A', 'C'})<<endl;
}

