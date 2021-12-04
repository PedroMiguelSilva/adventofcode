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

vector<pair<string,int>> readStringIntPairFromStdout(const int fileSize) {
    vector<pair<string,int>> answer(fileSize);
    for(int i = 0; i < fileSize; i++) {
        cin >> answer[i].first >> answer[i].second;
    }

    return answer;
}

vector<string> readStringFromStdout(const int fileSize) {
    vector<string> answer(fileSize);
    for(int i = 0; i < fileSize; i++) {
        cin >> answer[i];
    }
    return answer;
}

vector<int> readCommaSeparatedIntStdout(const int drawn_size) {
    vector<int> answer(drawn_size);
    int val;
    char trash;
    for(int i = 0; i < drawn_size-1; i++) {
        cin >> answer[i];
        cin >> trash;
    }
    cin >> answer[answer.size()-1];
    return answer;
}