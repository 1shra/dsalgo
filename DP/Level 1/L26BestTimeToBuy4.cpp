// Cooling down period add for 1day after selling
#include <iostream>
using namespace std;
int timeTobuy(int prices[], int n)
{
    int obsp = -prices[0];
    int ossp = 0;
    int ocsp = 0;

    for (int i = 1; i < n; i++)
    {
        int nbsp = 0;
        int nssp = 0;
        int ncsp = 0;
        if (ocsp - prices[i] > obsp)
        {
            nbsp = ocsp - prices[i];
        }
        else
        {
            nbsp = obsp;
        }
        if (obsp + prices[i] > ossp)
        {
            nssp = obsp + prices[i];
        }
        else
        {
            nssp = ossp;
        }

        if (ocsp < ossp)
        {
            ncsp = ossp;
        }
        else
        {
            ncsp = ocsp;
        }

        obsp = nbsp;
        ossp = nssp;
        ocsp = ncsp;
    }
    return ossp;
}
int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 0, 2};
    cout << timeTobuy(arr, n);
    return 0;
}
