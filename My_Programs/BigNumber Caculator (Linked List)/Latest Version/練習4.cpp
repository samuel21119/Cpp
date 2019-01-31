#include "BigInteger.h"
#include <fstream>
#include <ctime>
using namespace std;
int main(){
    Number a, b, c;
    c = "1000000";
    a = 23;
    for (; c > 0; --c){
        a *= 10;
    }
    cout << 1;
    cin >> c;
    b = 12;
    cout << a * b;
}
