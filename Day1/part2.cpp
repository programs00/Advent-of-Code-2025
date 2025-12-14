#include <bits/stdc++.h>
using namespace std;

void check(int curr, int start, int &pass) {
    if(start < curr) {
        while(curr > start) {
            curr--;
            if(curr % 100 == 0) pass++;
        }
    }
    else {
        while(curr < start) {
            curr++;
            if(curr % 100 == 0) pass++;
        }
    }
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;

    int curr = 50;
    int pass = 0;
    
    while(getline(in, line)) {
        if(!line.empty()) {
            int steps = abs(stoi(line.substr(1)));
            int start;
            
            if(line[0] == 'L') {
                start = curr - steps;
            }
            else {
                start = curr + steps;
            }
            
            check(curr, start, pass);
            curr = start % 100;
            if(curr < 0) curr += 100;
        }
    }
    
    cout << pass << '\n';
}