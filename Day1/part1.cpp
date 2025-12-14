#include <bits/stdc++.h>
using namespace std;

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;

    int start = 50;
    int pass = 0;
    while(getline(in, line)) {
        if(!line.empty()) {
            if(line[0] == 'L') {
                line = line.substr(1);
                start += -stoi(line);
            }
            else if(line[0] == 'R') {
                line = line.substr(1);
                start += stoi(line);
            }
            if(start < 0) start = 100 + start;
            start = start % 100;
            if(start == 100) start = 0;
            if(start == 0) pass++;
        }
    }
    cout << pass << '\n';
}