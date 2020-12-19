#include <bits/stdc++.h>

using namespace std;

int main() {
  int c;
  unordered_set<int> s;
  while(cin >> c) {
    if(s.count(2020-c)) {
      cout << (c*(2020-c)) << endl;
      return 0;
    }
    s.insert(c);
  }
}
