#include<bits/stdc++.h>
using namespace std;
int n ;
int arr[100005] ;

bool isprime( long long num ){
    for( long long i = 2 ; i * i <= num ; ++i ){
        if( num % i == 0 ) return false ;
    }
    return true ;
}

int main(void){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d", &arr[i]) ;
    }
    if( n >= 3 ){
        if( n == 3 &&
           arr[ 0 ] + arr[ 1 ] + arr[ 2 ] == 3 ) puts("No") ;
        else puts("Yes") ;
    }
    else{
        if( n == 1 ){
            if( arr[ 0 ] <= 2 ){
                puts("No") ;
                return 0 ;
            }
            if( isprime( arr[ 0 ] ) ) puts("No") ;
            else puts("Yes") ;
        } else {
            if( !isprime( arr[0] ) || !isprime( arr[1] ) || !isprime( arr[0] + arr[1] ) ) puts("Yes") ;
            else puts("No") ;
        }
    }
    return 0;
}