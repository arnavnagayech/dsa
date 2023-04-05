#include<bits/stdc++.h>
using namespace std;

int N=1000000;
int sieve[1000001];

void createSieve()      // O(nlog(logn))
{
    for(int i=2;i<=N;i++)
        sieve[i]=i;

    for(int i=2; i*i <= N; i++)
    {
        if(sieve[i] == i)
        {
            for(int j= i*i ; j<=N ;j+=i)
            {
                if(sieve[j] == j)
                    sieve[j]=i;
            }
        }
    }
}

int main() 
{
    createSieve();
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        while(n!=1)
        {
            cout << sieve[n] << " ";
            n=n/sieve[n];
        }
    }
    
    return 0; 
}