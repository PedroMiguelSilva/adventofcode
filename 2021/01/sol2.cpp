#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

const int FILE_SIZE = 2000;
const int WINDOW_SIZE = 3;

int main() {
    vector<int> input = readIntListFromStdout(FILE_SIZE);
    int counter = 0;

    int prevWindowVal = 0;
    for(int i = 0; i < WINDOW_SIZE; i++) {
        prevWindowVal += input[i];
    }

    int currWindowVal = prevWindowVal;
    for(int i = WINDOW_SIZE; i < FILE_SIZE; i++) {
        currWindowVal += input[i];
        currWindowVal -= input[i-WINDOW_SIZE];

        if(currWindowVal > prevWindowVal) {
            counter++;
        }
        prevWindowVal = currWindowVal;
    }

    cout << "Answer is " << counter << endl;
    assert(counter == 1311);
}