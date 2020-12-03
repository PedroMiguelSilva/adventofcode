#include <bits/stdc++.h>

using namespace std;

int f(int r, int d) {
  string l;
  int cl=0,c = 0, lc=0;
  while(getline(cin, l)) {
    if(lc++%d) continue;
    if(l[cl] == '#') c++;
    cl = (cl+r)%31;
  }
  return c;
}

int main(int argc, char** argv) {
  if(argc != 3) return 1;
  cout << f(atoi(argv[1]),atoi(argv[2])) << endl;
}
