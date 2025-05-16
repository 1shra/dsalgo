#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a = 5;
    int rep = a+1;
    int k = a*2;
    int l = 2;
    int flag1 =1;
    for(int i=1; i<=a;i++){
        int m=0;
        cout<<i<<" ";
        for(int j=1;j<3;j++){
            // Column with spaces
            {
                if(i==a || i==1){
                    if(!(j%2) ){
                        if(i==1){
                            cout<<rep*j<<" ";
                        }
                        else{
                            cout<<"  ";
                        }
                    }
                else{
                    if(i==a){
                        cout<<rep*j<<" ";
                    }
                    else{
                        cout<<"  ";
                    }
                }
                }
                else{
                    cout<<"  ";
                }
                // Column without spaces 
                if(flag1){
                    m=i+k;
                    cout<<m<<" ";
                    k-=2;
                    flag1=0;
                }
                else{
                    m+=l;
                    cout<<m<<" ";
                    l+=2;
                    flag1=1;
                }
            }

        }
        cout<<endl;
    }
    return 0;
}