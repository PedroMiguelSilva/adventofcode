#include <bits/stdc++.h>

using namespace std;

bool isValid(const vector<int>& w, int tmp) {
  for(int i = 0; i < (int)w.size(); i++) {
    for(int j = 0; j < (int)w.size(); j++) {
      if(w[i]+w[j] == tmp) return true;
    }
  }
  return false;
}

int main() {
  int tmp;
  vector<int> window(25);
  int index = 0;

  for(int i = 0; i < 25; i++)
    cin >> window[i];

  while(cin >> tmp) {
    // Check if the elements in the window are enough to add up to 'tmp'
    if(!isValid(window, tmp)) {
      cout << tmp << endl;
      return 0;
    }
    window[index] = tmp;
    index = (index+1)%25;
  }
}
