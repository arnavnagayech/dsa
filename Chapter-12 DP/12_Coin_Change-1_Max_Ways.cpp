#include <bits/stdc++.h>
using namespace std;

int countNoOfWays(int coin[], int n, int sum)
{
    int t[n + 1][sum + 1];
    
    // Initialization
    for (int i = 1; i < sum+1; i++)
        t[0][i] = 0;

    for (int i = 0; i < n+1; i++)
        t[i][0] = 1;
    
    // Function
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] =  t[i][j - coin[i - 1]]  + t[i - 1][j] ;
            
            else
                t[i][j] = t[i - 1][j];
        }
    }
 
    return t[n][sum];
}
 
int main()
{
    int n = 4;
    int coin[] = {1,2,5,10};
    int sum = 3;
 
    cout << "No. of Ways= " << countNoOfWays(coin, n, sum) << endl;

    return 0;
}