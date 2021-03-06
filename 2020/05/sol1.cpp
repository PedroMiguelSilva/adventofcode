#include <bits/stdc++.h>

using namespace std;

const unsigned ROW_DIGITS = 7, COL_DIGITS = 3;


pair<int,int> decodeSeat(string s) {
  int row = 0, col = 0;
  
  for(unsigned i = 0; i < ROW_DIGITS; i++)
    if(s[i] == 'B')
      row += pow(2,ROW_DIGITS-i-1);
  for(unsigned i = 0; i < COL_DIGITS; i++)
    if(s[i+ROW_DIGITS] == 'R')
      col += pow(2, COL_DIGITS-i-1);
  
  return {row,col};
}

int getId(int r, int c) {
  return r*8+c;
}

int main() {

  string line;
  int answer=-1;
  while(getline(cin,line)) {
    pair<int,int> seat = decodeSeat(line);
    answer=max(answer,getId(seat.first,seat.second));
  }
  cout << answer << endl;

  return 0;
}
