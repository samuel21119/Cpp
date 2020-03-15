#include <iostream>
using namespace std;

typedef long long ll;
ll a[300010], b[300010];
int n, m, i, j, re;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    while (i < n || j < m) {
        if (a[i] == b[j]) {
            j++;
            i++;
            re++;
        }
        else if (a[i] > b[j]) {
            if (j > m)
                break;
            b[j + 1] += b[j], j++;
        }
        else if (a[i] < b[j])  {
            if (i > n)
                break;
            a[i + 1] += a[i], i++;
        }
    }
    if (a[i] != b[j])
        re = -1;
    cout << re << '\n';
    return 0;
}
