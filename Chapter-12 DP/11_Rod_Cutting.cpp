#include <bits/stdc++.h>
using namespace std;
 
int RodCutting(int price[], int length[], int n, int N)
{
    int t[n+1][N+1];

    for(int i=0;i<n+1;i++)  //Initialization
    {   
        for(int j=0; j<N+1; j++)
            if(i==0 || j==0)
                t[i][j]=0;
    }

    for(int i=1; i< n+1; i++)
    {   
        for(int j=1; j< N+1; j++)
        {
            if (length[i - 1] <= j)
                t[i][j] = max( price[i-1] + t[i-1][j-length[i-1]] , t[i-1][j]);
 
            else if(length[i - 1] > j)
                t[i][j]= t[i-1][j];
        }
    }

    return t[n][N];
}
 
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    
    int length[n];
    for (int i = 0; i < n; i++) 
        length[i] = i + 1;
    
    int Max_len = n;
 
    cout << "Maximum obtained value  is "<< RodCutting(price, length, n, Max_len) << endl;
}