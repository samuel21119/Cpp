/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 16:28:37 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string s, curS;
int curI;
map<string, int> ans;
bool ifBig(char c) {
	return 'A' <= c && c <= 'Z';
}
bool ifSmall(char c) {
	return 'a' <= c && c <= 'z';
}
bool ifInt(char c) {
	return !ifBig(c) && !ifSmall(c);
}
string getElement(string &s, int &i) {
	string re;
	re += s[i];
	i++;
	while (i < s.length() && ifSmall(s[i]))
		re += s[i++];
	return re;
}
int getInt(string &s, int &i) {
	int re = 0;
	while (i < s.length() && ifInt(s[i]))
		re = re * 10 + s[i++] - '0';
	return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cout << s << '\n';

    for (int i = 0; i < s.length(); ) {
    	curS = getElement(s, i);
    	curI = getInt(s, i);
    	if (!curI)
    		curI = 1;
    	ans[curS] += curI;
    	
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
    	cout << it->first << ':' << it->second << '\n';
    return 0;
}
