    #include <iostream>
    #include <algorithm>
    using namespace std;
     
    int n;
    int in1[1000], in2[1000];
    int main() {
        int t;
        cin >> t;
        while (t--) {
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> in1[i];
            for (int i = 0; i < n; i++)
                cin >> in2[i];
            sort(in1, in1 + n);
            sort(in2, in2 + n);
            for (int i = 0; i < n; i++)
                cout << in1[i] << ' ';
            cout << '\n';
            for (int i = 0; i < n; i++)
                cout << in2[i] << ' ';
        }
    }