#include <bits/stdc++.h>

using namespace std;

int counter = 0;

bool isDateValid(string s, string min, string max) {
  return min <= s && s <= max;
}

bool isCombValid(string s) {
  stringstream ss(s);
  int val; string term;
  ss >> val >> term;
  if(term=="cm" && 150 <= val && val <= 193)
    return true;
  if(term=="in" && 59 <= val && val <= 76)
    return true;
  return false;
}

bool isHCLValid(string s) {
  if(s.size() != 7) return false;
  if(s[0] != '#') return false;
  for(int i = 1; i < (int)s.size(); i++) {
    char c = s[i];
    if(!(('0'<=c&&c<='9') || ('a'<=c&&c<='f')))
      return false;
  }
  return true;
}

set<string> ecls = {"amb", "blu", "brn","gry", "grn", "hzl", "oth"};
bool isECLValid(string s) {
  return ecls.count(s);
}

bool isPIDValid(string s) {
  if(s.size() != 9) return false;
  for(int i = 0; i < (int)s.size(); i++) {
    if(!isdigit(s[i])) return false;
  }
  return true;
}

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
  if(vals.size() == 8 || (vals.size() == 7 && !vals.count("cid"))) {
    // Don't increase counter if anything fails
    if(!isDateValid(vals["byr"], "1920", "2002")) return;
    if(!isDateValid(vals["iyr"], "2010", "2020")) return;
    if(!isDateValid(vals["eyr"], "2020", "2030")) return;
    if(!isCombValid(vals["hgt"])) return;
    if(!isHCLValid(vals["hcl"])) return;
    if(!isECLValid(vals["ecl"])) return;
    if(!isPIDValid(vals["pid"])) return;
    counter++;
  }
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
