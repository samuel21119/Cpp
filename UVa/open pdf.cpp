/*************************************************************************
  > File Name: o.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 21 16:26:30 2018
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int problem, folder;
        string path, f, p;
        stringstream ss, t1, t2;
        ss << argv[i];
        ss >> problem;
        folder = problem / 100;
        t1 << folder; t1 >> f;
        t2 << problem; t2 >> p;
        //path = "open ./PDF/" + f + "/" + p + ".pdf"; //macOS
        path = "okular ./PDF/" + f + "/" + p + ".pdf"; //Linux + Okular
        // /Users/samuel/c/UVA
        // path = "open ./PDF/" + f + "/" + p + ".pdf";
        system(path.c_str());
    }
}
