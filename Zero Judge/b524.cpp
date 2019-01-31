#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
    char a[100000];
    while(cin>>a){
        int b=0,y=0;
        for(int i=0;a[i]!=0;i++){
            if(a[i]=='y'){
                b+=abs(i-y);
                y+=3;
            }
        }
        cout<<b<<endl;
    }
    return 0;
}
