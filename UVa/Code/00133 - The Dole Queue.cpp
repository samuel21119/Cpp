/*************************************************************************
  > File Name: 133 - The Dole Queue.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jul 16 23:45:44 2018
*************************************************************************/

#include <cstdio>
#include <cstring>
int n, k, m;
bool visit[20];

int go(int s, int dir, int km) {
    while (km--)
        while (1) {
            s += dir;
            if (s > n)
                s = 1;
            else if (s < 1)
                s = n;
            //printf("%d %d %d\n",km, s, visit[s]);
            if (!visit[s])
                break;
        }
    return s;
}

int main() {
    while (scanf("%d%d%d", &n, &k, &m) != EOF) {
        if (!(n | k | m))
            return 0;
        memset(visit, 0, sizeof visit);
        int last = n;
        int K = 1;
        int M = n;
        while (last) {
            K = go(K - 1, 1, k);
            M = go(M + 1, -1, m);
            if (last < n)
                printf(",");
            printf("%3d", K);
            if (K == M)
                last--;
            else {
                printf("%3d", M);
                last -= 2;
            }
            visit[K] = visit[M] = 1;
        }
        printf("\n");
    }
    return 0;
}
