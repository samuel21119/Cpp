#include <iostream>
#include <cstdio>
using namespace std;
int prime[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool number_used[17];
int number_array[16], length;
bool if_prime(int a) {
    for (int i = 0; i <= 9; i++) {
        if (prime[i] == a)
            return true;
    }
    return false;
}
void dfs(int index) {
    for (int i = 2; i <= length; i++) {
        if (!if_prime(number_array[index - 1] + i) || number_used[i] != 0) {
            continue;
        }
        number_array[index] = i;
        number_used[i] = 1;
        if (index < length - 1) {
            dfs(index + 1);
        }else {
            if (if_prime(i + 1)) {
                for (int i = 0; i < length; i++) {
                    cout << number_array[i];
                    if (i < length - 1) {
                        cout << " ";
                    }
                    else {
                        cout << '\n';
                    }
                }
            }
        }
        number_used[i] = 0;
    }
}
int main() {
    int Case = 1;
    while (cin >> length) {
        for (int i = 0; i < 16; i++) {
            number_used[i + 1] = false;
            number_array[i] = 0;
        }
        number_used[1] = true;
        number_array[0] = 1;
        printf("Case %d:\n", Case++);
        if (length == 0) {
            cout << 0;
        }
        else if (length == 1) {
            cout << 1;
        }else {
            dfs(1);
        }
        printf("\n");
    }
}
