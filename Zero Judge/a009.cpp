#include <iostream>
using namespace std;
int main() {
    string input;
    std::ios::sync_with_stdio(0);
    while (getline(cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            cout << (char)((int)input[i] - 7);
        }
        cout << '\n';
    }
}
