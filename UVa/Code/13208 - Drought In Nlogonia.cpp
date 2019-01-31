/*************************************************************************
  > File Name: 13208 - Drought In Nlogonia.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:38:58 2017
*************************************************************************/

#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
int h[10005];
int x[10005], x2;
int r[10005];
int a, test, j, _min, _max, _maxX;
long long sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--) {
        _min = 0;
        cin >> a >> x2;
        for (int i = 0; i < x2; i++) {
            cin >> x[i];
        }
        for (int i = 0; i <= x2; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < x2; i++) {
            r[i] = h[i + 1];
            if (h[i] <= h[i + 1]) {
                r[i] = h[i];
                j = i;
                _max = 0;
                _maxX = -1;
                while (j >= _min) {
                    if (h[j] >= h[i + 1]) {
                        r[i] = h[i + 1];
                        break;
                    }
                    if (_max < h[j]) {
                        _max = h[j];
                        _maxX = j;
                    }
                    j--;
                }
                if (j >= _min) {
                    for (int k = j; k < i + 1; k++)
                        r[k] = r[i];
                }else if (_max > h[i]){
                    for (int k = _maxX; k < i + 1; k++) 
                        r[k] = _max;
                }else
                    _min = i + 1;
            }
        }
        sum = 0;
        for (int i = 0; i < x2; i++) {
            sum += x[i] * r[i];
        }
        cout << sum * a << endl;
    }
    return 0;
}

