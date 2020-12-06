#include <bits/stdc++.h>

using namespace std;

int sum = 0;

void test_case(string doc) {
  unordered_set<char> s;
  for(int i = 0; i < (int)doc.size();i++) {
    if(doc[i]=='\n')continue;
    s.insert(doc[i]);
  }
  sum+=s.size();
}


int main() {
  string line;
  string doc="";
  bool firstLine = true;
  while(getline(cin,line)) {
    if(line.empty()) {
      test_case(doc);
      doc="";
      firstLine = true;
    } else {
      if(!firstLine)
        doc+='\n';
      doc+=line;
      firstLine =false;
    }
  }
  if(!doc.empty()) test_case(doc);

  cout << sum << endl;

  return 0;
}
