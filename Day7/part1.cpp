#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& input, int r, int c, int n, int m, int& sum) {
    if(r < n-1){
        if(input[r+1][c] == '^') {
            sum++;
            input[r+1][c+1] = '|';
            input[r+1][c-1] = '|';
            solve(input, r+1, c-1, n, m, sum);
            solve(input, r+1, c+1, n, m, sum);
        }
        else if (input[r+1][c] == '.') {
            input[r+1][c] = '|';
            solve(input, r+1, c, n, m, sum);
        }
    }

}

int calculate( vector<string>& input) {
    int sum = 0;
    int n = input.size();
    int m = input[0].size();

    int s = find(input[0].begin(), input[0].end(), 'S') - input[0].begin();
    input[1][s] = '|';

    solve(input, 1, s, n, m, sum);
    return sum;
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

    int ans = calculate(input);
    cout << ans << '\n';
}