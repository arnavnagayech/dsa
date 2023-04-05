#include<bits/stdc++.h>
using namespace std;

int N=1000000;
bool sieve[1000001];

void createSieve()      // O(nlog(logn))
{
    for(int i=2;i<=N;i++)
        sieve[i]=true;

    for(int i=2; i*i <= N; i++)
    {
        if(sieve[i] == true)
        {
            for(int j= i*i ; j<=N ;j+=i)
                sieve[j]=false;
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

        if(sieve[n]==true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0; 
}