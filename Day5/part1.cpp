#include <bits/stdc++.h>
using namespace std;

bool isFresh(long long n, const vector<pair<long long, long long>>& ranges) {
    for(const auto& range : ranges) {
        if(n >= range.first && n <= range.second) {
            return true;
        }
    }
    return false;
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }
    long long ans = 0;
    string line;
    vector<pair<long long, long long>> ranges;
    while(getline(in, line)) {
        if(line.empty()) continue;
        if(line.find('-') != string::npos) {
            long long start = stoll(line.substr(0, line.find('-')));
            long long end = stoll(line.substr(line.find('-') + 1));
            ranges.push_back({start, end});
        }
        else{
            long long n = stoll(line);
            if(isFresh(n, ranges)) {
                ans++;
            }
        }        
    }
    cout << ans << '\n';
}