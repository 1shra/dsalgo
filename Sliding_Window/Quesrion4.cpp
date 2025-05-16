/*
Given an array of characters where each character represents a fruit tree, 
you are given two baskets and your goal is to put maximum number of fruits in each basket. 
The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree. 
You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both the baskets.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

max_fruits(const string &vec){
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
        }
        max_fruits=max(max_fruits,window_end-window_start+1);
    }
    return max_fruits;
}  
int main(){
    cout<<"The maximum number of fruits in both the basket: "<<max_fruits("ABCAC")<<endl;
    return 0;
}

