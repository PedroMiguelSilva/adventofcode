#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

const int FILE_SIZE = 1000;

int main() {
    vector<pair<string,int>> input = readStringIntPairFromStdout(FILE_SIZE);

    int pos = 0, depth = 0;

    for(int i = 0; i < FILE_SIZE; i++) {
        string dir = input[i].first;
        int dist = input[i].second;

        if(dir == "forward") {
            pos += dist;
        } else if(dir == "down") {
            depth += dist;
        } else if(dir == "up") {
            depth -= dist;
        } else {
            assert(false);
        }
    }

    cout << "Answer is " << pos*depth << endl;
    assert(pos*depth == 1692075);
}