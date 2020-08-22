#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define ppp pair<pii,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define CL(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
#define DI(x) (int)(x-'0')
#define LL_MAX (1LL<<60)
#define DB 0
#define DBG(x) if(DB)cout << #x << " : " << x << '\n'
#define PRALL(v) if(DB)for(auto it : v)cout<<v<<' '; NL;
#define NL cout<<'\n';
#define FND(S,x) (S.find(x)!=S.end())
#define bit(x,y) (!!(x&(1<<y)))
typedef long long ll;
typedef long double ld;

int N, A[16];
vector<int> v[17];
bool has[1<<16];
int T[1<<16];

bool chk(int x)
{
    CL(has);
    has[0] = 1;
    T[0] = 0;
    FOR(i,1,N)
    {
        for( int b : v[i-1] )
        {
            FOR(j,0,N-1)
            {
                if( b&(1<<j) )continue;
                if( !has[b] )continue;
                int nb = (b|(1<<j));
                int nx = max(A[j],T[b]+A[j]);
                if( nx > x )continue;
                if( !has[nb] )
                {
                    has[nb] = 1;
                    T[nb] = nx;
                }
                else
                {
                    T[nb] = min(T[nb], nx);
                }
            }
        }
    }
    if( has[ (1<<N)-1 ] )return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    FOR(i,0,N-1)cin>>A[i];

    FOR(b,0,(1<<N)-1)
    {
        int c = __builtin_popcount(b);
        v[c].pb(b);
    }

    int l = -1e7, r = 1e7;
    while( l+1<r )
    {
        int m = (l+r)/2;
        if( chk(m) )r = m;
        else l = m;
    }
    cout<<r<<'\n';

    return 0;
}