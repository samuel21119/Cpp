/*************************************************************************
  > File Name: 939 - Genes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 20:29:58 2018
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int str(string in) {
    if (in == "dominant")     return 2;
    if (in == "recessive")    return 1;
    if (in == "non-existent") return 0;
    return -1;
}
string str(int in) {
    if (in == 2) return "dominant";
    if (in == 1) return "recessive";
    return "non-existent";
}
struct G{
    vector<string> child;
    vector<string> parents;
    int gene = -1;
};
map<string, G> r;
void setGene(G &in) {
    string p1, p2;
    int g1, g2;
    p1 = in.parents[0];  p2 = in.parents[1];
    if (r[p1].gene < 0)
        setGene(r[p1]);
    if (r[p2].gene < 0)
        setGene(r[p2]);
    g1 = r[p1].gene;  g2 = r[p2].gene;
    if (g1 + g2 >= 3)
        in.gene = 2;
    else if (g1 + g2 == 2)
        in.gene = 1;
    else in.gene = 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    string a, b;
    map<string, G>::iterator it;
    for (cin >> c; c--;) {
        cin >> a >> b;
        G in, in2;
        it = r.find(a);
        if (it != r.end())
            in = it->second;
        if (str(b) == -1) {
            in.child.push_back(b);
            it = r.find(b);
            if (it != r.end())
                in2 = it->second;
            in2.parents.push_back(a);
            r[b] = in2;
        }else
            in.gene = str(b);
        r[a] = in;
    }
    for (it = r.begin(); it != r.end(); it++) {
        if (it->second.gene < 0)
            setGene(it->second);
        cout << it->first << " " << str(it->second.gene) << endl;
    }
    return 0;
}

