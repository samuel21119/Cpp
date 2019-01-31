/*************************************************************************
  > File Name: 10056 - What is the Probability.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:47:54 2017
*************************************************************************/

#include <cstdio>
using namespace std;
double pow(float a, int n) {
    double r = 1;
    for (int i = 0; i < n; i++)
        r *= a;
    return r;
}
int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int a, b;
        double c, ans;
        scanf("%d%lf%d", &a, &c, &b);
        if (c == 0.0)
            printf("0.0000\n");
        else {
            ans = (pow(1.0-c,b-1) * c) / (1-pow(1-c, a)); 
            printf("%.4f\n", ans);
        }
    }
    return 0;
}
