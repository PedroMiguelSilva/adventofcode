#include <bits/stdc++.h>
#include "../reader.hpp"

using namespace std;

const int INPUT_SIZE = 1000;

struct TrieNode {
    int counter;
    int value;
    TrieNode* node0;
    TrieNode* node1;

    TrieNode(int _value, int _counter) {
        value = _value;
        counter = _counter;
        node0 = NULL;
        node1 = NULL;
    } 
};

void insertInTrie(TrieNode* node, const string& s, int index) {
    if(index >= s.size()) return;

    if(s[index] == '0') {
        if(node->node0) {
            node->node0->counter++;
        } else {
            node->node0 = new TrieNode(0, 1);
        }
        insertInTrie(node->node0, s, index+1);
    } else {
        if(node->node1) {
            node->node1->counter++;
        } else {
            node->node1 = new TrieNode(1, 1);
        }
        insertInTrie(node->node1, s, index+1);
    }
}

string findCode(TrieNode* node, bool mostCommon) {
    string answer = "";

    while(node && node->node0 && node->node1) {
        if(node->node0->counter > node->node1->counter) {
            if(mostCommon) {
                answer += "0";
                node = node->node0;
            } else {
                answer += "1";
                node = node->node1;
            }
        } else {
            if(mostCommon) {
                answer += "1";
                node = node->node1;
            } else {
                answer += "0";
                node = node->node0;
            }
        }
    }

    while(node->node0 || node->node1) {
        if(node->node0) {
            answer += "0";
            node = node->node0;
        } else if(node->node1) {
            answer += "1";
            node = node->node1;
        }
    }

    return answer;
}

int main() {
    vector<string> input = readStringFromStdout(INPUT_SIZE);

    TrieNode* root = new TrieNode(-1, -1);
    for(int i = 0; i < INPUT_SIZE; i++) {
        insertInTrie(root, input[i], 0);
    }
    string oxygen = findCode(root, true);
    string co2 = findCode(root, false);

    long long unsigned int o = stoi(oxygen, 0, 2);
    long long unsigned int c = stoi(co2, 0, 2);

    cout << "Answer is " << o*c << endl;
    assert(o*c == 3969126);
}