#include <bits/stdc++.h>
using namespace std;

bool check(int i, int j, vector<string>& lines) {
    int n = lines.size();
    int m = lines[0].length();

    int res = 0;

    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    for(const auto& dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;

        if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
            if(lines[ni][nj] == '@') {
                res++;
            }
        }
    }
    if(res >= 4) {
        return false;
    }
    else return true;
    
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;
    vector<string> lines;

    while(getline(in, line)) {
        lines.push_back(line);
    }

    int ans = 0;

    int n = lines.size();
    int m = lines[0].length();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(lines[i][j] == '@') {
                if(check(i, j, lines)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}

