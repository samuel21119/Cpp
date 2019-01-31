#include <bits/stdc++.h>
using namespace std;
struct node {
    int w, v, c;
    node(){}
    node(int a, int b, int C) {
        w = a;
        v = b;
        c = C;
    }
}in[2010];
struct d {
    int num = 0;
    vector<int> choose;
}dp[10010];
int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        in[i] = {a, b, c};
    }
    for (int i = 0; i < n; i++) {
        int t = in[i].w;
        int v = in[i].v;
        for (int j = w; j >= t; j--) {
            if (dp[j - t].num + v > dp[j].num) {
                dp[j] = dp[j - t];
                dp[j].num += v;
                dp[j].choose.emplace_back(i);
            }
        }
    }
    double ans = 0;
    for (int i = w; i >= 0; i--) {
        double t = dp[i].num;
        ans = max(ans, t);
        int b = 0;
        //sort(dp[i].choose.begin(), dp[i].choose.end());
        for (int j = 0; j < dp[i].choose.size(); j++) {
            while (b < dp[i].choose[j]) {
                if (w - i < in[b].w)
                    ans = max(ans, t + double(in[b].v) * double(w - i) / double(in[b].w) - in[b].c);
                b++;
            }
            b++;
        }
        //cout << i << '\n';
        while (b < n) {
                //cout <<  double(in[b].v) * double(w - i) / double(in[b].w) - in[b].c << '\n';
            if (w - i < in[b].w)
                ans = max(ans, t + double(in[b].v) * double(w - i) / double(in[b].w) - in[b].c);
            b++;
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

