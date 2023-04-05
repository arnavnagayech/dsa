#include <bits/stdc++.h>
using namespace std;

/* Time Complexity: O(sum*n)
   Auxiliary Space: O(sum*n) */

bool subsetSum(int arr[], int sum, int n)
{
    bool t[n+1][sum+1];

    for(int i=0;i<n+1;i++)  //Initialization
    {   
        for(int j=0; j<sum+1; j++)
        {   
            if(i==0)
                t[i][j]=false;

            if(j==0)
                t[i][j]=true;
        }
    }

    for(int i=1; i< n+1; i++)
    {   
        for(int j=1; j< sum+1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = ( t[i-1][j-arr[i-1]] ) || ( t[i-1][j] );
 
            else if(arr[i - 1] > j)
                t[i][j]= t[i-1][j];
        }
    }

    return t[n][sum];
}

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    else
        return subsetSum(arr, sum, n);
 
}

int main()
{
    int arr[] = { 3, 1, 1, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";

    return 0;
}
 