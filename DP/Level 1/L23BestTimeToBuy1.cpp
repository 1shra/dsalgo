//Single Transacation 
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> prices = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    int least = INT_MAX;
    int Oprofit = 0;
    int profit2day = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (least > prices[i])
        {
            least = prices[i];
        }
        profit2day = prices[i] - least;

        if(profit2day>Oprofit){
            Oprofit=profit2day;
        }
    }
    cout << Oprofit;
    return 0;
}