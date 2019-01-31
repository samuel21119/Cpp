#include "BigInteger.h"
#include <fstream>
#include <ctime>
using namespace std;
int main(){
    int n,a[2095000],index,length,temp,temp2,i,print[5];
    long long int temp3;
    clock_t t1, t2;
    ofstream output;
	a[0]=1;
    length=0;
    index=0;
    printf("Enter a number\n");
    scanf("%d",&n);
    output.open("output.txt");
    output << n << "\!:\n";
    t1 = clock();
    for (;n>=2;n--) {
        printf("%d\n",n);
        temp=0;
        for (i=0;i<=index;i++) {
            temp3=(((long long int)a[i])*((long long int)n))+temp3;
            if (temp3 < 0){
                return 0;
            }
            a[i]=temp3%1000000000;
            temp3=temp3/1000000000;
        }
        while (temp3>0) {
            a[++index]=temp3%1000000000;
            temp3=temp3/1000000000;
        }
    }
    for (i=index;i>=0;i--) {
        temp = 100000000;
        temp2 = a[i];
        for (int j = 0; j < 9; j++) {
            print[j] = temp2 / temp;
            temp2 -= print[j] * temp;
            temp /= 10;
        }
        if (i == index) {
            temp = print[0];
            for (int j = 0; j < 9;) {
                if (temp > 0) {
                    //printf("%d",print[j++]);
                    output << print[j++];
                    length++;
                }else {
                    temp = print[++j];
                }
            }
        }else {
            for (int j = 0; j < 9; j++) {
                //printf("%d",print[j]);
                output << print[j];
                length++;
            }
        }
    }
    t2 = clock();
    output << "\nLength: " << length << "\nTime Used: " << (t2 - t1)/CLOCKS_PER_SEC << " seconds";
    return 0;

}
