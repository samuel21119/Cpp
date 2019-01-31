/*************************************************************************
  > File Name: 11516 - WiFi.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:33:04 2017
*************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
int house[100005];
int ap, _house, _max;
bool Depend(int mid) {
    int count = 0;
    int i, j;
    int mid2 = mid * 2;
    i = j = 0;
    while (1) {
        while (house[j] <= house[i] + mid2 && j < _house)
            j++;
        count++;
        i = j;
        if (count > ap)
            return false;
        if (j >= _house)
            return true;
    }
}
int main() {
    int count;
    scanf("%d", &count);
    while (count--) {
        scanf("%d%d", &ap, &_house);
        for (int i = 0; i < _house; i++)
            scanf("%d", house + i), house[i] *= 2;
        if (ap >= _house) {
            printf("0.0\n");
            continue;
        }
        sort(house, house + _house);
        _max = house[_house - 1];
        int down, up;
        int mid;
        down = 0;
        up = house[_house - 1];
        while (up - down > 1) {
            mid = (down + up)/2;
            if (Depend(mid))
                up = mid;
            else
                down = mid;
        }
        printf("%.1f\n", up / 2.0);
    }
    return 0;
}

