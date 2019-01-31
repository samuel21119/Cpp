/*************************************************************************
  > File Name: 10090 - Marbles.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:54:59 2017
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;
ll exgcd(ll a, ll b, ll&x, ll&y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a%b, y, x);
    ll t = x;
    y = y - a/b*t;
    return r;
}
int main()
{
    ll n;
    ll c1,n1,c2,n2;
    while(scanf("%lld",&n),n)
    {
        scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
        ll x,y,a1,a2;
        ll g=exgcd(n1,n2,x,y);
        if(n%g!=0)
        {
            printf("failed\n");
            continue;
        }
        ll k1=ceil(-n*x*1.0/n2);
        ll k2=floor(n*y*1.0/n1);
        if(k1>k2)
        {
            printf("failed\n");
            continue;
        }
        if(c1*n2<c2*n1)
        {
            a1=n*x/g+n2*k2/g;
            a2=n*y/g-n1*k2/g;
        }
        else
        {
            a1=n*x/g+n2*k1/g;
            a2=n*y/g-n1*k1/g;
        }
        printf("%lld %lld\n",a1,a2);
    }
    return 0;
}
