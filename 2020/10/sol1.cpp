#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> volt = {0};
  int t;
  while(cin >> t) {
    volt.push_back(t);
  }

  sort(volt.begin(), volt.end());

  int n1 = 0, n3 = 1;
  for(int i = 0; i < (int)volt.size()-1;i++) {
    if(volt[i+1]-volt[i] == 1)
      n1++;
    if(volt[i+1]-volt[i]==3)
      n3++;
  }

  cout << n1 << " " << n3 << endl;
  cout << n1*n3 << endl;
}
