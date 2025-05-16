#include <iostream>
#include <vector>
using namespace std;

int Recursivefibonacci(int n, int &i)
{
    i++;
    if (n == 0 || n == 1)
    {
        return n;
    }
    return Recursivefibonacci(n - 1, i) + Recursivefibonacci(n - 2, i);
}

//Top down approch
int tdfib(int n, vector<int> &vec,int &k)
{
    k++;
    if (n == 0 || n == 1)
    {
        vec[n] = n;
        return vec[n];
    }
    if (vec[n] != -1)
    {
        return vec[n];
    }
    vec[n] = tdfib(n - 1, vec,k) + tdfib(n - 2, vec,k);
    return vec[n];
}

//Bottom up approch

int bufib(int n){
    vector<int> vec(n+1,-1);
    vec[0]=0;
    vec[1]=1;
    for(int i=2;i<n;i++){
        vec[i]=vec[i-1]+vec[i-2];
    }
    return vec[n-1];
}
int main()
{
    int n = 5;
    int k = 0;
    cout << Recursivefibonacci(n, k);
    cout<<" "<<k<<endl;
    cout<<"Top down Apporch"<<endl;
    vector<int> vec(n + 1, -1);
    k=0;
    int c = tdfib(n, vec,k);
    cout << c<<" "<<k<<endl;
    cout<<"Bottom Up Apporch"<<endl;
    cout<<bufib(n+1)<<endl;

    return 0;
}