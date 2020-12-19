#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void test_case(string& doc) {
  stringstream ss(doc);
  map<string,string> vals;
  char c;
  string k,v;
  bool ended = false;
  while(ss) {
    ss.get(c);
    k=v="";
    while(c != ':') {
      k+=c; ss.get(c);
    }
    ss.get(c);
    while(c != ' ') {
      if(ss.tellg() == -1) {
        ended=true;
        break;
      }
      v+=c; ss.get(c);
    }
    vals[k]=v;
    if(ended)break;
  }
  if(vals.size() == 8 || (vals.size() == 7 && !vals.count("cid")))
    counter++;
}

int main() {
  string doc = "", line;
  while(getline(cin, line)) {
    if(line.empty()) {
      doc.erase(0,1);
      test_case(doc);
      doc="";
    }
    else {
      doc+= " " + line;
    }
  }
  if(!doc.empty()){
    doc.erase(0,1);
    test_case(doc);
  }
  cout << counter << endl;

  return 0;
}
