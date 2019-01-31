/*************************************************************************
  > File Name: 11959 - Dice.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jan 26 14:45:46 2018
*************************************************************************/

#include <iostream>
using namespace std;

struct DICE {
    int dice[6];
};
void A (DICE &a) {
    int t = a.dice[0];
    a.dice[0] = a.dice[2]; a.dice[2] = a.dice[1]; a.dice[1] = a.dice[3]; a.dice[3] = t;
}

void B (DICE &a) {
    int t = a.dice[2];
    a.dice[2] = a.dice[5]; a.dice[5] = a.dice[3]; a.dice[3] = a.dice[4]; a.dice[4] = t;
}

void C (DICE &a) {
    int t = a.dice[0];
    a.dice[0] = a.dice[4]; a.dice[4] = a.dice[1]; a.dice[1] = a.dice[5]; a.dice[5] = t;
}

int cmp (const DICE a, const DICE  b) {
    for (int k = 0; k < 6; k++)
        if (a.dice[k] != b.dice[k])
            return a.dice[k] - b.dice[k];
    return 0;
}

void turn(DICE &a) {
    DICE b;
    b = a;
    for (int i = 0; i < 4; i++) {
        A(b);
        for (int j = 0; j < 4; j++) {
            B(b);
            for (int k = 0; k < 4; k++) {
                C(b);
                if (cmp(a, b) > 0)
                    a = b;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    int in1[6], in2[6];
    char temp;
    cin >> c;
    while (c--) {
        for (int i = 0; i < 6; i++) {cin >> temp; in1[i] = temp - '0';}//上下前左後右
        for (int i = 0; i < 6; i++) {cin >> temp; in2[i] = temp - '0';}
        DICE a, b; //上下前後左右
        a.dice[0] = in1[0];
        a.dice[1] = in1[1];
        a.dice[2] = in1[2];
        a.dice[3] = in1[4];
        a.dice[4] = in1[3];
        a.dice[5] = in1[5];
        b.dice[0] = in2[0];
        b.dice[1] = in2[1];
        b.dice[2] = in2[2];
        b.dice[3] = in2[4];
        b.dice[4] = in2[3];
        b.dice[5] = in2[5];
        turn(a);
        turn(b);
        int i;
        for (i = 0; i < 6; i++)
            if (a.dice[i] != b.dice[i])
                break;
        if (i != 6)
            cout << "Not Equal\n";
        else
            cout << "Equal\n";
    }
    return 0;
}
