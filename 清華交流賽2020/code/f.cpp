#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[ 200005 ] ;
int v[ 100005 ] ;
int main(void){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d" ,&v[ i ]) ;
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = i + 1 ; j < n ; ++j ){
            int num = v[ i ] ^ v[ j ] ;
            if( vis[ num ] ){
                puts("Yes") ;
                return 0 ;
            } else {
                vis[num] = true ;
            }
        }
    }
    puts("No");
    return 0;
}
