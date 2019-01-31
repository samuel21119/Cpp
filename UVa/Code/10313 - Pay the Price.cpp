/*************************************************************************
  > File Name: 10313 - Pay the Price.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Mar  9 17:41:36 2018
*************************************************************************/

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

long long dp[301][1001];

int main() {
    char input[20];
    int temp;
    int mode[4];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 300; i++) 
        for (int j = i; j <= 300; j++)
            for (int k = 1; k <= 1000; k++)
                dp[j][k] += dp[j - i][k - 1];
    for (int i = 0; i <= 300; i++)
        for (int j = 1; j <= 1000; j++)
            dp[i][j] += dp[i][j - 1];
    while (cin.getline(input, 20)) {
        string s(input);
        stringstream ss(s);
        mode[3] = 0; 
        while (ss >> temp)
            mode[mode[3]++] = temp;
        if (mode[3] == 3 && mode[1] == 0)
            mode[3] = 2, mode[1] = mode[2];
        switch (mode[3]) {
            case 1:
                cout << dp[mode[0]][mode[0]] << '\n';
                break;
            case 2:
                cout << dp[mode[0]][mode[1]] << '\n';
                break;
            case 3:
                long long temp = dp[mode[0]][mode[2]] - dp[mode[0]][mode[1] - 1];
                if (temp < 0)
                    cout << "0\n";
                else
                    cout << temp << '\n';
        }
    }
}
