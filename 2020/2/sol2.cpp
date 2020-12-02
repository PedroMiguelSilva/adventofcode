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
    if((word[lower-1] == c)^(word[upper-1] == c)) {
      counter++;
    }
  }

  cout << counter << endl;

  return 0;
}
