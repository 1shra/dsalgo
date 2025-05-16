//Multiple transaction and no overlapping

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> prices = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    int profit=0;
    int sd=0;
    int bd=0;

    for (int i = 1; i < prices.size(); i++)
    {
        if(prices[i]>=prices[i-1]){
            sd++;
        }
        else{
            profit+=(prices[sd]-prices[bd]);
            sd=bd=i;
        }
    }
    profit+=(prices[sd]-prices[bd]);
    cout << profit;
    return 0;
}