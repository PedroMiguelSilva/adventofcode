#include <bits/stdc++.h>

using namespace std;


int edgeCounter = 0;
unordered_map<int,vector<pair<int,int>>> edges;
unordered_map<string,int> dic;

const string STRING_DELIMITER = " bags contain ";
const string NO_CHILD = "no other bags.";

int getBagId(string s) {
  int answer;
  if(dic.count(s)) {
    answer = dic[s];
  } else {
    dic[s] = edgeCounter;
    answer = edgeCounter;
    edgeCounter++;
  }
  return answer;
}

void parse(string line) {
  size_t s = line.find(STRING_DELIMITER);
  string key = line.substr(0, s);
  int currKey = getBagId(key);
  string rest = line.substr(s+STRING_DELIMITER.size());

  if(rest == NO_CHILD) return;

  stringstream ss(rest);
  int qt;
  string v1,v2,v3;
  while(ss >> qt >> v1 >> v2 >> v3) {
    int childKey = getBagId(v1 + " " + v2);
    edges[currKey].push_back(make_pair(childKey, qt));
  }
}

int dfs(int i) {
  if(edges[i].size() == 0) return 1;

  int numChilds = 0;
  for(int j = 0; j < (int) edges[i].size(); j++) {
    numChilds += (dfs(edges[i][j].first)*edges[i][j].second);
  }
  return numChilds+1;
}

int main() {
  
  string line;
  while(getline(cin,line))
    parse(line);

  int shinyId = getBagId("shiny gold");
  int answer = dfs(shinyId);
  cout << answer - 1 << endl;

  return 0;
}
