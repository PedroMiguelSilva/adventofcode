#include <bits/stdc++.h>

using namespace std;

int main() {
  string l;
  int cl=0,c = 0;
  while(getline(cin, l)) {
    if(l[cl] == '#') c++;
    cl = (cl+3)%31;
  }
  printf("%d\n",c);
}
