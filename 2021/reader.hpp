#include <bits/stdc++.h>

using namespace std;

vector<int> readIntListFromStdout(const int fileSize) {
    string newLine;
    vector<int> answer(fileSize);

    for(int i = 0; i < fileSize; i++) {
        cin >> newLine;
        answer[i] = stoi(newLine);
    }

    return answer;    
}