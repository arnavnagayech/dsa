// Eg.- 2 is min prime factor of how many numbers from 1 to 10^6

#include<bits/stdc++.h>
using namespace std;

int N=1000000;
int sieve[1000001];

void createSieve()      
{
    for(int i=2;i<=N;i++)
        sieve[i]=1;

    for(int i=2; i*i <= N; i++)
    {
        if(sieve[i] == 1)
        {
            for(int j= i*i ; j<=N ;j+=i)
            {
                if(sieve[j] != 0)
                {
                    sieve[i]++;
                    sieve[j]=0;
                }
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

        cout << sieve[n] << endl;
    }
    return 0; 
}