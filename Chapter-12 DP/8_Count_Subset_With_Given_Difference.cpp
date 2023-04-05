#include <bits/stdc++.h>
using namespace std;

/* Time Complexity: O(sum*n)
   Auxiliary Space: O(sum*n) */

int countSubsetSum(int arr[], int n, int sum)
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
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int countSubsetDiff(int arr[], int n, int diff)
{
    int sumArr = 0;
    for (int i = 0; i < n; i++)
        sumArr += arr[i];

    int sum = (diff + sumArr)/2;

    return countSubsetSum(arr, n, sum);
}

int main()
{
    int n = 4;
    int arr[] = {1,1,3,2};
    int diff = 1;
 
    cout << (countSubsetDiff(arr, n, diff)) << endl;

    return 0;
}