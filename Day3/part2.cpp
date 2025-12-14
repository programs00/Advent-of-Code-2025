#include <bits/stdc++.h>
using namespace std;

void check( string line, long long &ans ) {
    int n = line.length();
    int keep = 12;  
    
    string result = "";
    int toRemove = n - keep; 
    for (int i = 0; i < n; i++) {
        while (!result.empty() && toRemove > 0 && result.back() < line[i]) {
            result.pop_back();
            toRemove--;
        }
        result += line[i];
    }
    while (toRemove > 0) {
        result.pop_back();
        toRemove--;
    }
    
    long long joltage = stoll(result);
    ans += joltage;
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;
    long long ans = 0;
    while(getline(in, line)) {
        check(line, ans);
    }
    cout << ans << '\n';;
}