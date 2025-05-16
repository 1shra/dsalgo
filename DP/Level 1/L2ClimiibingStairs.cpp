#include <iostream>
#include <vector>
using namespace std;
// recursive
int climbing(int a)
{
    if (a <= 0)
    {
        return 1;
    }
    if (a == 1 || a == 2)
    {
        return a;
    }
    int k = climbing(a - 1) + climbing(a - 2) + climbing(a - 3);
    return k;
}

// meomorization
int memoclimbing(int a, vector<int> &vec)
{
    if (a == 0)
    {
        return 1;
    }
    if (vec[a] != -1)
    {
        return vec[a];
    }
    vec[a] = climbing(a - 1) + climbing(a - 2) + climbing(a - 3);
    return vec[a];
}
// tabulation
int tabclimbing(int a, vector<int> &vec)
{
    vec[0] = 1;
    vec[1] = 1;
    vec[2] = 2;
    int n = vec.size();
    for (int i = 3; i < n; i++)
    {
        vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
    }
    return vec[n - 1];
}
int main()
{
    int a = 4;
    cout << "recursion" << endl;
    cout << climbing(a) << endl;
    cout << "memorization" << endl;
    vector<int> vec(a + 1, -1);
    cout << memoclimbing(a, vec) << endl;
    cout << "Tabulation" << endl;
    vector<int> vec1(a + 1, -1);
    cout << tabclimbing(a, vec1) << endl;
    for (int i : vec1)
    {
        cout << i << " ";
    }
    return 0;
}