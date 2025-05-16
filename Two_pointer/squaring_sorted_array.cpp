#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1{-2,-1,0,2,3,4,25};
    int count=vec1.size()-1;
    vector<int>vec2(count+1);
    int j=vec1.size()-1;
    int i=0;
    while(i<j){
        int g = vec1[i]*vec1[i];
        int h = vec1[j]*vec1[j];
        if(g>h){
            vec2[count]=g;
            i++;
            count--;
        }
        else if(g==h){
            vec2[count]=g;
            i++;
            count--;
        }
        else
        {
            vec2[count]=h;
            j--;
            count--;
        }
    }
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<endl;
    }
}