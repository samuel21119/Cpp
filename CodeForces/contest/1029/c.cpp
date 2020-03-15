/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 25 00:21:21 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const int maxn = 300005;

int n;
pii num[maxn];
int LST[maxn*4], RST[maxn*4];

void init(int id, int l, int r){
    if(l == r){
        LST[id] = num[l].first;
        RST[id] = num[l].second;
    }else{
        int mid = (l+r) / 2;
        int lson = 2 * id + 1, rson = 2 * id + 2;
        init(lson, l, mid);
        init(rson, mid+1, r);
        LST[id] = max(LST[lson], LST[rson]);
        RST[id] = min(RST[lson], RST[rson]);
    }
}
int Rquery(int nl, int nr, int id, int ql, int qr){
    if(nl>qr||ql>nr){
        return 10000000;
    }else if(ql<= nl&&nr<= qr){
        return RST[id];
    }else{
        int lson = 2*id+1, rson = 2*id+2, mid = (nl+nr)/2;
        int xl, xr;
        xl = Rquery(nl, mid, lson, ql, qr);
        xr = Rquery(mid+1, nr, rson, ql, qr);
        return min(xl, xr);
    }
}
int Lquery(int nl, int nr, int id, int ql, int qr){
    if(nl>qr||ql>nr){
        return -1;
    }else if(ql<= nl&&nr<= qr){
        return LST[id];
    }else{
        int lson = 2*id+1, rson = 2*id+2, mid = (nl+nr)/2;
        int xl, xr;
        xl = Lquery(nl, mid, lson, ql, qr);
        xr = Lquery(mid+1, nr, rson, ql, qr);
        return max(xl, xr);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    int xl, xr, res;

    while(cin >> n){
        for(i  =  0; i < n; i++)
            cin>>num[i].first>>num[i].second;
        sort(num, num+n);
        res = 0;
        init(0, 0, n-1);
        
        for(i = 0;i<n;i++){
            xl = max(Lquery(0, n-1, 0, 0, i-1), Lquery(0, n-1, 0, i+1, n-1));
            xr = min(Rquery(0, n-1, 0, 0, i-1), Rquery(0, n-1, 0, i+1, n-1));
            if(xr-xl>0){
                res = max(res, xr-xl);
            }
        }
        cout<<res<<'\n';
    }
}
