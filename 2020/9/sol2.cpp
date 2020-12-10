#include <bits/stdc++.h>

using namespace std;

int main() {
  int tmp;
  vector<unsigned long long> all;
  while(cin >> tmp)
    all.push_back(tmp);

  int goal = 85848519;
  int sum = all[0]+all[1];
  int l = 0, r = 1;
  while(sum != goal) {
    if(sum < 0) break;
    if(sum < goal) {
      r++;
      sum+=all[r];
    } else {
      sum-=all[l];
      l++;
    }
  }
  int mysum = 0;
  int maxV=-1;
  int minV = INT_MAX;
  for(int i = l; i <= r; i++) {
    maxV = max(maxV, (int)all[i]);
    minV = min(minV, (int)all[i]);
  }

  cout << maxV + minV << endl;
}
