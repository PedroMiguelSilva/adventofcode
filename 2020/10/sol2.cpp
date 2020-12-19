#include <bits/stdc++.h>

using namespace std;

vector<int> volt;
int answer =0;
map<int,int> cache;


int main() {
  int t;
  while(cin >> t) {
    volt.push_back(t);
  }

  volt.push_back(0);
  sort(volt.begin(), volt.end());
  volt.push_back(volt[volt.size()-1]+3);

  int n = volt.size();
  vector<long long> cache(n+1, 0);
  cache[0] = 1;
  for (int i = 1; i < n; i++)
  {
    if (i - 1 >= 0 && volt[i] - volt[i - 1] <= 3)
    {
      cache[i] += cache[i - 1];
    }
    if (i - 2 >= 0 && volt[i] - volt[i - 2] <= 3)
    {
      cache[i] += cache[i - 2];
    }
    if (i - 3 >= 0 && volt[i] - volt[i - 3] <= 3)
    {
      cache[i] += cache[i - 3];
    }
  }

  cout << cache[n-1] << endl;
}
