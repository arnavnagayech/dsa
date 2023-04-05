#include <bits/stdc++.h>
using namespace std;
 
int knapSack(int wt[], int val[], int n, int W)
{
    int t[n+1][W+1];
    memset(t, -1, sizeof(t));
 
    if (n == 0 || W == 0)       // Base Case
        return 0;

    if(t[n][W] != -1)
        return t[n][W];
 
    if (wt[n - 1] <= W)
        return t[n][W] = max( val[n - 1] + knapSack(wt, val, n - 1, W - wt[n - 1]),
            knapSack(wt, val, n - 1, W));
 
    else if(wt[n - 1] > W)
        return t[n][W]= knapSack(wt, val, n - 1, W);

    return -1;
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