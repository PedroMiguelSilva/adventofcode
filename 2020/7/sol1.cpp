#include <bits/stdc++.h>

using namespace std;


int edgeCounter = 0;
unordered_map<int,vector<int>> edges;
unordered_map<string,int> dic;

const string STRING_DELIMITER = " bags contain ";

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

void test_case(string line) {
  size_t s = line.find(STRING_DELIMITER);
  string key = line.substr(0, s);
  int currKey = getBagId(key);
  string rest = line.substr(s+STRING_DELIMITER.size());

  if(rest == "no other bags.") return;

  stringstream ss(rest);
  int qt;
  string v1,v2,v3;
  while(ss >> qt >> v1 >> v2 >> v3) {
    int childKey = getBagId(v1 + " " + v2);
    edges[childKey].push_back(currKey);
  }
}

void dfs(int i, unordered_set<int>& visited) {
  visited.insert(i);

  for(int j = 0; j < (int) edges[i].size(); j++) {
    if(!visited.count(edges[i][j])) {
      dfs(edges[i][j], visited);
    }
  }
}

int main() {
  
  string line;
  while(getline(cin,line))
    test_case(line);

  int shinyId = getBagId("shiny gold");
  unordered_set<int> visited;
  dfs(shinyId, visited);
  visited.erase(shinyId);
  cout << visited.size() << endl;

  return 0;
}
