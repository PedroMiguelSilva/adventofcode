#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

const int INPUT_SIZE = 1000;
const int BIN_SIZE = 12;

int main() {
    vector<string> input = readStringFromStdout(INPUT_SIZE);

    vector<int> counter(BIN_SIZE, 0);

    for(int i = 0; i < INPUT_SIZE; i++) {
        for(int j = 0; j < BIN_SIZE; j++) {
            counter[j] += (input[i][j]-'0');
        }
    }

    string gamma = "", epsilon = "";
    for(int i = 0; i < BIN_SIZE; i++) {
        if(counter[i] > INPUT_SIZE/2) {
            gamma += "1";
            epsilon += "0";
        } else if(counter[i] < INPUT_SIZE/2) {
            gamma += "0";
            epsilon += "1";
        } else {
            assert(false);
        }
    }
    long long unsigned int g = stoi(gamma, 0, 2);
    long long unsigned int e = stoi(epsilon, 0, 2);

    cout << "Answer is " << g*e << endl;
    assert(g*e == 738234);
}
