#include <iostream>
#include <vector>
using namespace std;

int countways(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    vector<vector<int>> vec(n, vector<int>(3));
    vec[1][0] = k;
    vec[1][1] = k * (k - 1);
    vec[1][2] = vec[1][0] + vec[1][1];

    for (int i = 2; i < n; i++)
    {
        vec[i][0] = vec[i - 1][1];
        vec[i][1] = vec[i - 1][2] * (k - 1);
        vec[i][2] = vec[i][0] + vec[i][1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return vec[n - 1][2];
}

int main()
{
    int a = 5;
    int b = 2;
    cout << countways(a, b);
    return 0;
}