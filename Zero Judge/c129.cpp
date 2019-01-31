#include <iostream>
using namespace std;
char input[3000][3000];
int global_m, global_n;
bool dfs(int m, int n) {
    int result = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i + m >= 0 && i + m < global_m &&
                j + n >= 0 && j + n < global_n){
                if (input[i + m][j + n] == '@') {
                    result = 1;
                    input[i + m][j + n] = '*';
                    dfs(i + m, j + n);
                }
            }
        }
    }
    return result;
}
int main() {
    int m, n, count;
    while (cin >> m >> n) {
        if (m == n && n == 0)
            break;
        global_m = m;
        global_n = n;
        count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> input[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count += dfs(i, j);
            }
        }
        cout << count << endl;
    }
}
