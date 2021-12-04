#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

int drawn_size = 100;

struct Board {
    vector<vector<int>> m;
    vector<int> colWin, rowWin;
    int id;
    Board(int _id) {
        id = _id;
        m = vector<vector<int>>(5, vector<int>(5));
        colWin = vector<int>(5, 0);
        rowWin = vector<int>(5, 0);
    }

    void read() {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> m[i][j];
            }
        }
    }

    bool isWinning(int i, int j) {
        bool winCol = true, winRow = true;
        for(int k = 0; k < 5; k++) {
            if(m[i][k] != -1) winRow = false;
            if(m[k][j] != -1) winCol = false;
        }
        return winCol || winRow;
    }

    int calculateWin(int drawn) {
        int sum = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0 ; j < 5; j++) {
                if(m[i][j] != -1) sum += m[i][j];
            }
        }
        return drawn*sum;
    }

    int draw(int n) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(m[i][j] == n) {
                    m[i][j] = -1;
                    if(isWinning(i, j)) {
                        return calculateWin(n);
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> numbers = readCommaSeparatedIntStdout(drawn_size);

    vector<Board*> boards;
    int id = 0;
    while(!cin.eof()) {
        Board* b = new Board(id++);
        b->read();
        boards.push_back(b);
    }

    for(int i = 0; i < (int)numbers.size(); i++) {
        int drawn = numbers[i];
        for(int j = 0; j < (int)boards.size(); j++) {
            int res = boards[j]->draw(drawn);
            if(res != -1) {
                cout << "Answer is " << res << endl;
                assert(res == 58412);
                return 0;
            }
        }
    }

    return 0;
}