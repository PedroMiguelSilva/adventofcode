#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

int getCoord(int x, int y) {
    return x + 1000*y;
}

int main() {
    vector<pair<Point, Point>> input = readLines();

    unordered_map<int, int> m;
    for(int i = 0; i < (int)input.size(); i++){
        Point p1 = input[i].first;
        Point p2 = input[i].second;

        if(p1.x == p2.x) {
            for(int j = min(p1.y, p2.y); j <= max(p1.y, p2.y); j++) {
                m[getCoord(p1.x, j)]++;
            }
        }
        else if(p1.y == p2.y) {
            for(int j = min(p1.x, p2.x); j <= max(p1.x, p2.x); j++) {
                m[getCoord(j, p1.y)]++;
            }
        }
        else {
            for(int j = 0; j < (p2.x-p1.x+1); j++) {
                int y = (p1.y > p2.y)? p1.y-j: p1.y+j;
                m[getCoord(p1.x+j, y)]++;
            }
        }
    }

    int counter = 0;
    for(pair<int,int> p: m) {
        if(p.second >= 2) {
            counter++;
        }
    }

    cout << "Answer is " << counter << endl;
    assert(counter == 20484);
}