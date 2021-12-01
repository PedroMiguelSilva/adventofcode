#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

const int FILE_SIZE = 2000;

int main() {
    vector<int> input = readIntListFromStdout(FILE_SIZE);
    int counter = 0;

    for(int i = 1; i < FILE_SIZE; i++) {
        if(input[i] > input[i-1]) {
            counter++;
        }
    }

    cout << "Answer is " << counter << endl;
    assert(counter == 1288);
}