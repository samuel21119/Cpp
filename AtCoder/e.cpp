    /*************************************************************************
      > File Name: e.cpp
      > Author: Samuel
      > Mail: enminghuang21119@gmail.com
      > Created Time: Sat Apr  4 20:26:19 2020
    *************************************************************************/
     
    #include <bits/stdc++.h>
    using namespace std;
     
    int n, k, c;
    string s;
    int workL[200010], workR[200010];
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> k >> c;
        cin >> s;
        int last = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x')
                continue;
            int now = i + 1;
            if (last == -1 || last + c < now) {
                last = now;
                workL[now] = ++cnt;
                if (cnt == k)
                    break;
            }
        }
        last = -1;
        cnt = k;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'x')
                continue;
            int now = i + 1;
            if (last == -1 || last - c > now) {
                last = now;
                workR[now] = cnt--;
                if (cnt == 0)
                    break;
            }
        }
        for (int i = 1; i <= n; i++)
            if (workL[i] && workL[i] == workR[i])
                cout << i << '\n';
        return 0;
    }
