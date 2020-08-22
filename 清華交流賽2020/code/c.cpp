#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node{

    int w ;
    Node *L , *R ;

}*root[505];

Node * makenode(int num){
    Node * res = ( Node * ) malloc ( sizeof( Node ) ) ;
    res -> L = res -> R = NULL ;
    res -> w = num ;
    return res ;
}
int n, Q ;
int op ;
int ql, qr ;
int x ;
int val ;
void ADD( Node * ptr , int num ){

    if( ptr -> w > num ){
        if( ptr -> L == NULL ){
            ptr -> L = makenode( num ) ;
        } else {
            ADD( ptr -> L , num ) ;
        }
    } else {
        if( ptr -> R == NULL ){
            ptr -> R = makenode( num ) ;
        } else {
            ADD( ptr -> R , num ) ;
        }
    }
}
int getans( Node *ptr , int num ){

    if( ptr == NULL ) return 0 ;
    else{

        if( ptr -> w == num ){
            return num ;
        } else {

            if( ptr -> w > num ){
                return ptr -> w + getans( ptr -> L , num ) ;
            } else {
                return ptr -> w + getans( ptr -> R , num ) ;
            }

        }
    }

}
int32_t main(void){
    scanf("%lld%lld",&n,&Q);
    while(Q--){
        scanf("%lld",&op) ;
        if( op == 1 ){
            scanf("%lld%lld%lld", &ql, &qr, &val) ;
            for( int i = ql ; i <= qr ; ++i ){
                if ( root[ i ] == NULL ){
                    root[ i ] = makenode( val ) ;
                } else {
                    ADD( root[ i ] , val ) ;
                }
            }
        } else {
            scanf("%lld%lld", &x, &val) ;
            printf("%lld\n" , getans( root[ x ] , val ));
        }
    }
    return 0;
}
