#include<iostream>
#include<string>
using namespace std;
string check(int n){
    if(n<10){
        return "0"+to_string(n);
    }
    else{
        return to_string(n);
    }
}

int main(){
    int a;
    int w;
    int flag=1;
    cout<<"Enter the number of row "<<endl;
    cin>>a;
    int m=(a-1)*3+1;
    int n=a-1;
    
    for(int i=1;i<=a;i++){
        cout<<check(i)<<" ";
        for(int j = 0; j<2; j++)
        {

            if(flag){
                if(i==a){
                    for(int e=1;e<a-1;e++){

                        cout<<check(i+e)<<" ";
                    }
                }
                else{
                    for(int e=1;e<a*3-5;e++){
                        cout<<" ";
                    }                    
                }
                cout<<check(m);
                flag=0;
            }                
            else{
                if(i==1){
                    cout<<" ";
                    for(int e=1;e<a-1;e++){
                        cout<<check(m+e)<<" ";
                    }
                }
                else{
                    for(int e=1;e<=a*3-5;e++){
                        cout<<" ";
                    }
                }
                cout<<check(m+n);
                flag=1;
            }
                
            }
            
            
        n+=2;
        cout<<endl;
        m-=1;

        }
        return 0;
    }
