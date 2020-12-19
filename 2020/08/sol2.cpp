#include <bits/stdc++.h> 

using namespace std;

int lineCounter = 0;
vector<pair<int,int>> ops;
int answer;


int solve(int idx, unordered_set<int> lineNumber, int acc) {
  if(idx >= (int)ops.size()) {
    return acc;
  }
  while(1) {
    if(idx >= (int) ops.size()) return acc;
    if(lineNumber.count(idx)) return INT_MIN;
    lineNumber.insert(idx);

    switch(ops[idx].first) {
      case 0:
        idx++;
        break;
      case 1:
        acc += ops[idx].second;
        idx++;
        break;
      case 2:
        idx += ops[idx].second;
        break;
    }
  }
  if(idx >= (int)ops.size()) return acc;
  return INT_MIN;
}

int main() {
  unordered_set<int> lineNumber;

  string op;
  char sign;
  int val;

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

  int idx = 0;
  int acc = 0;
  int t;
  while(!lineNumber.count(idx)) {
    lineNumber.insert(idx);

    switch(ops[idx].first) {
      case 0:
        t = solve(idx+ops[idx].second, lineNumber, acc);
        if(t != INT_MIN) {
          cout << t << endl;
          return 0;
        }
        idx++;
        break;
      case 1:
        acc += ops[idx].second;
        idx++;
        break;
      case 2:
        t = solve(idx+1, lineNumber, acc);
        if(t != INT_MIN) {
          cout << t << endl;
          return 0;
        }

        idx += ops[idx].second;
        break;
    }
  }

  return 0;
}
