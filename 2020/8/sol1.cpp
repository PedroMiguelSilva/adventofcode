#include <bits/stdc++.h> 

using namespace std;

int lineCounter = 0;

int main() {
  unordered_set<int> lineNumber;

  string op;
  char sign;
  int val;
  int acc = 0;

  vector<pair<int,int>> ops;
  while(cin >> op >> sign >> val) {
    int mult = (sign=='+')?1:-1;
    int iop;
    if(op=="nop")
      iop = 0;
    else if(op == "acc")
      iop = 1;
    else
      iop = 2;
    ops.push_back(make_pair(iop,val*mult));
  }

  int currIndex = 0;
  while(!lineNumber.count(currIndex)) {
    lineNumber.insert(currIndex);

    switch(ops[currIndex].first) {
      case 0:
        currIndex++;
        break;
      case 1:
        acc += ops[currIndex].second;
        currIndex++;
        break;
      case 2:
        currIndex += ops[currIndex].second;
        break;
    }
  }
  cout << acc << endl;

  return 0;
}
