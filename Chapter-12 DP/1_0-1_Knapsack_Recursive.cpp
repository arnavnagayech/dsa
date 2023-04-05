#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int wt[], int val[], int n, int W)
{
    if (n == 0 || W == 0)       // Base Case
        return 0;
 
    if (wt[n - 1] <= W)
        return max( val[n - 1] + knapSack(wt, val, n - 1, W - wt[n - 1]),
            knapSack(wt, val, n - 1, W));
 
    else if(wt[n - 1] > W)
        return knapSack(wt, val, n - 1, W);
        
}
 
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(wt, val, n, W);
    return 0;
}