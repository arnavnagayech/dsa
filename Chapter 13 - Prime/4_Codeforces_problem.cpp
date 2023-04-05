// Find a,b,c so that { a * b * c = n } if [a != b != c = 1]
// constraint -> n <= 10^9

#include<bits/stdc++.h>
using namespace std; 
 
int main() 
{
    int n;
    cin >> n;

    int a=n,b=n,c=n;
    for(int i=2;i*i<=n ; i++)
    {
        if(n%i==0)
        {
            a=i;
            break;
        }
    }

    n=n/a;

    for(int i=2;i*i<=n ; i++)
    {
        if(n%i == 0)
        {
            if(i != a)
                b = min(b,i);

            if ((n/i) != i)
            {
                if((n/i) != a)
                    b=min(b,n/i);
            }
        }
    }

    c = n/b;

    if(a !=b  && b !=c && c>1)
        cout << "Yes" << a << b << c << endl;
    else
        cout << "No" << endl;

    return 0;  
}