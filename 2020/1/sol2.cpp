#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> in(200);
  for(int i = 0; i < 200; i++)
    cin >> in[i];

  unordered_map<int,int> m;
  for(int a: in)
    for(int b: in)
      m[a+b] = a*b;

  for(int a: in)
    if(m[2020-a]) { cout << m[2020-a]*a << endl; return 0; }
}
