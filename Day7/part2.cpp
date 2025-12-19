#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& input, int r, int c, int n, int m) {
    if(r < n-1){
        if(input[r+1][c] == '^') {
            input[r+1][c+1] = '|';
            input[r+1][c-1] = '|';
            solve(input, r+1, c-1, n, m);
            solve(input, r+1, c+1, n, m);
        }
        else if (input[r+1][c] == '.') {
            input[r+1][c] = '|';
            solve(input, r+1, c, n, m);
        }
    }

}

map<pair<int,int>, long long> dp;
long long count(vector<string>& input, int r, int c, int n, int m) {

    pair<int, int> pos = {r, c};
    if(dp.find(pos) != dp.end()) {
        return dp[pos];
    }
    long long ans = 0;
    if(input[r][c] == '|'){
        if(r == n-1 && input[r][c] == '|') {
            ans = 1;   
        }
        else if(input[r+1][c] == '^') {
            ans = count(input, r+1, c-1, n, m) + count(input, r+1, c+1, n, m);
        }
        else if (input[r+1][c] == '|') {
            ans = count(input, r+1, c, n, m);
        }
    }
    dp[pos] = ans;
    return ans;
}

void calculate( vector<string>& input) {
    int n = input.size();
    int m = input[0].size();

    int s = find(input[0].begin(), input[0].end(), 'S') - input[0].begin();
    input[1][s] = '|';

    solve(input, 1, s, n, m);
    long long ans = count(input, 1,s, n,m);
    cout << ans << '\n';
}


int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    vector<string> input;
    string line;
    while(getline(in, line)) {
        input.push_back(line);
    }

    calculate(input);
}