/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 24 23:38:38 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n,k;
int fail[55];
void init(string s){
    int n = s.size();
    int k = -1;
    int i;
    fail[0 ] = -1;

    for(i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k + 1])
            k = fail[k];
        if(s[i] == s[k+1])
            k++;
        fail[i] = k;
    }
}

int main(){
    int j;
    string s;
    while(cin >> n>> k){
        cin >> s;
        init(s);
        k--;
        cout << s;
        while(k--)
            for(j = fail[n-1] + 1; j < n; j++)
                cout << s[j];
        cout<<'\n';
    }
    return 0;
}

