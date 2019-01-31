/*************************************************************************
  > File Name: 1264 - Binary Search Tree.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 10 08:54:27 2018
*************************************************************************/

#include <iostream>
#include <cstdlib>
#define MOD 9999991
using namespace std;

long long C[20][20];
struct node {
    node* l;
    node* r;
    long long int c;
    int num;
    int curnum;
};
node* MALLOC() {
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->l = temp->r = NULL;
    temp->curnum = 0;
    temp->c = 1;
    temp->num = 1;
    return temp;
}
int c (node* N) {
    if (N->l == NULL && N->r == NULL)
        return 1;
    if (N->l != NULL && N->r != NULL){
        int temp = c(N->l);
        N->num = temp + c(N->r);
        N->c = C[N->num++][temp] % MOD * N->r->c % MOD * N->l->c % MOD;
    }
    else if (N->l != NULL) {
        N->num = c(N->l) + 1;
        N->c = N->l->c;
    }
    else {
        N->num = c(N->r) + 1;
        N->c = N->r->c;
    }
    return N->num;
}

void maketree (node* root, int num) {
    if (root->curnum == 0)
        root->curnum = num;
    else if (num < root->curnum) {
        if (root->l == NULL)
            root->l = MALLOC();
        maketree (root->l, num);
    }
    else {
        if (root->r == NULL)
            root->r = MALLOC();
        maketree (root->r, num);
    }
}
int numbers;
int main() {
    for (int i = 1; i < 20; i++) C[i][0] = 1;
    C[0][0] = 1;
    C[0][1] = 0;
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    int cases;
    cin >> cases;
    while (cases--) {
        node* head = MALLOC();
        cin >> numbers;
        for (int i = 0; i < numbers; i++) {
            int in;
            cin >> in;
            maketree (head, in);
        }
        int temp = c(head) - 1;
        if (head->l == NULL) {head->l = MALLOC(); head->l->num = 0;}
        if (head->r == NULL) {head->r = MALLOC(); head->r->num = 0;}
        cout << C[temp][head->l->num] % MOD * head->l->c % MOD * head->r->c % MOD << '\n';
    }
    return 0;
}
