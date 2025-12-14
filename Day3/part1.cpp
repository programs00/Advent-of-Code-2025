#include <bits/stdc++.h>
using namespace std;

void check( string line, int &ans ) {
    int maxJol = 0;
    for(int i = 0; i < line.length() -1; i++){
        for(int j = i + 1; j < line.length(); j++){
            int first = line[i] - '0';
            int second = line[j] - '0';
            int jol = first*10 + second;
            maxJol = max(maxJol, jol);
        }
    }
    ans += maxJol;
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;
    int ans = 0;  
    while(getline(in, line)) {
        check(line, ans);
    }
    cout << ans << '\n';;
}