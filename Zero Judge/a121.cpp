#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
vector<int> prime;
bool isP(int i) {
    int ii = sqrt(i);
    for (int j = 1; prime[j] <= ii; j++)
        if (!(i % prime[j]))
            return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, ans, j, k;
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    prime.push_back(7);
    prime.push_back(11);
    for (int i = 13; i <= 100010; i+=2)
        if (isP(i))
            prime.push_back(i);
    while (cin >> a >> b) {
        ans = 0;
        if (a == 1){
            if (b < 2)
                ans--;
            a++;
        }
        if (!(a%2)) {
            if (a == 2)
                ans++;
            a++;
        }
        for (int i = a; i <= b; i+=2) {
            if (isP(i))
                ans++;
        }
       cout << ans << '\n';
    }
}

