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
int TopDownFibonacci(int n, int &i, vector<int> &vec)
{
    i++;
    if (n == 0 || n == 1)
    {
        vec[n] = n;
        return vec[n];
    }
    if (vec[n] != -1)
    {
        return vec[n];
    }
    int vec[n] = TopDownFibonacci(n - 1, i, vec) + TopDownFibonacci(n - 2, i, vec);
    return vec[n];
}
int main()
{
    int n = 5;
    int k = 0;
    cout << Recursivefibonacci(n, k) << endl;
    cout << k;
    k = 0;
    vector<int> vec(n, 1);
    cout << TopdownFibonacci(n, k, vec) << endl;

    return 0;
}