#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    // Subset Sum
    bool t[n + 1][sum + 1];
    
    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
  
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = ( t[i-1][j-arr[i-1]] ) || ( t[i-1][j] );
            else
                t[i][j] = t[i - 1][j];
        }
    }
    
    // find Minimum 
    int diff = INT_MAX;
  
    for (int j = 0; j <= sum/2; j++)
    {
        if (t[n][j] == true)
            diff = min(diff, sum - 2 * j);
    }
    return diff;
}
  
int main()
{
    int arr[] = { 1,2,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is " << findMin(arr, n);
    return 0;
}