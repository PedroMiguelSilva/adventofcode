#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int counter = 0;
  while(getline(cin, line)) {
    stringstream ss(line);
    int lower,upper;
    char trash, c;
    string word;
    ss >> lower >> trash >> upper >> c >> trash >> word;
    unordered_map<char,int> f;
    for(char cc: word)
      f[cc]++;
    if(f[c] >= lower && f[c] <= upper)
      counter++;
  }

  cout << counter << endl;

  return 0;
}
