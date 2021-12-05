#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isValid(const vector<vector<char>>& state, int i, int j) {
    if(i < 0 || j < 0 || i >= (int)state.size() || j >= (int)state[i].size()) return false;
    return true;
}

int numberOfNeighbors(const vector<vector<char>>& state, int i, int j) {
    int counter = 0;
    for(int k = -1; k <= 1; k++) {
	for(int l = -1; l <= 1; l++) {
	    if(k == 0 && l == 0) continue;
	    for(int m = 1; m < (int)state.size(); m++) {
		int newx = i+k*m;
		int newy = j+l*m;
		if(isValid(state, newx, newy)) {
		    if(state[newx][newy] == 'L') break;
		    if(state[newx][newy] == '#') {
			counter++;
			break;
		    }
		}
	    }
	}
    }
    return counter;
}

pair<vector<vector<char>>,bool> nextState(vector<vector<char>> state) {
    vector<vector<char>> newState(state.size(),vector<char>(state[0].size()));
    bool change = false;
    for(int i = 0; i < (int)state.size(); i++) {
	for(int j = 0; j < (int)state[i].size(); j++) {
	    if(state[i][j] == '.') {
		newState[i][j] = '.';
		continue;
	    }
	    else if(state[i][j] == 'L' && (numberOfNeighbors(state, i, j) == 0)) {
		newState[i][j] = '#';
		change = true;
	    }
	    else if(state[i][j] == '#' && (numberOfNeighbors(state, i,  j) >= 5)) {
		newState[i][j] = 'L';
		change = true;
	    }
	    else {
		newState[i][j] = state[i][j];
	    }
	}
    }
    return {newState, change};
}

vector<vector<char>> readBoard() {
    string input;
    vector<vector<char>> answer;
    while(cin >> input) {
	vector<char> tmp;
	for(int i = 0; i < (int)input.size(); i++) {
	    tmp.push_back(input[i]);
	}
	answer.push_back(tmp);
    }
    return answer;
}

void print(vector<vector<char>> s) {
    for(int i = 0; i < (int)s.size(); i++) {
	for(int j = 0; j < (int)s[i].size(); j++) {
	    cout << s[i][j] << " ";
	}
	cout << endl;
    }
    cout << endl;
}

int countOccupied(const vector<vector<char>> b) {
    int counter = 0;
    for(int i = 0; i < (int)b.size(); i++) {
	for(int j = 0; j < (int)b[i].size(); j++) {
	    if(b[i][j] == '#') counter++;
	}
    }
    return counter;
}

int main() {
    pair<vector<vector<char>>, bool> state;
    vector<vector<char>> board = readBoard();
    state = {board, true};
    int iter = 0;
    char t;
    while(state.second) {
	state = nextState(state.first);
    }
    int answer = countOccupied(state.first);
    cout << "Answer is " << answer << endl;

}
