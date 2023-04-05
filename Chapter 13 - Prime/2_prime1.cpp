#include<bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    int count=0;

    for(int i=1; i*i <= n ; i++)
    {
        if(n%i==0)
        {
            count++;
            if ((n/i) != i)
                count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    isPrime(n)==2 ? cout << "Yes" : cout << "No";

    return 0;
}