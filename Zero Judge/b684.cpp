#include <stdio.h>

int node[1000001];

int main(void)
{
    int N,i,j,ans,right;

    scanf("%d", &N);
    for(i=1; i<=N; i++) {
        scanf("%d", &j);
        node[j] = i;
    }

    for(i=right=1,ans=0; i<=N-1; i++) {
        if( right ) {
            if( node[i+1] < node[i] ) {
                ans++;
                right = 0;
            }
        } else {
            if( node[i+1] > node[i] ) {
                ans++;
                right = 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
