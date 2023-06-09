#include <bits/stdc++.h>
using namespace std;

int MinNoOfCoins(int coin[], int n, int sum)
{
    int t[n + 1][sum + 1];
    
    // Initialization
    for (int i = 0; i < sum+1; i++)
        t[0][i] = INT_MAX-1;

    for (int i = 1; i < n+1; i++)
        t[i][0] = 0;

    for(int i=1 ; i< sum+1; i++)
    {
        if(i % coin[0] == 0)
            t[1][i] = i / coin[0];
        else
            t[1][i] = INT_MAX-1;
    }
    
    // Function
    for (int i = 2; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] =  min( 1 + t[i][j - coin[i - 1]] , t[i - 1][j]) ;
            
            else
                t[i][j] = t[i - 1][j];
        }
    }
 
    return t[n][sum];
}
 
int main()
{
    int n = 4;
    int coin[] = {9, 6, 5, 1};
    int sum = 11;
 
    cout << "Min No. of Coins= " << MinNoOfCoins(coin, n, sum) << endl;

    return 0;
}