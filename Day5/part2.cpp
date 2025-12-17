#include <bits/stdc++.h>
using namespace std;

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
        if(line.empty()) break;
        if(line.find('-') != string::npos) {
            long long start = stoll(line.substr(0, line.find('-')));
            long long end = stoll(line.substr(line.find('-') + 1));
            ranges.push_back({start, end});
        }       
    }

    sort(ranges.begin(), ranges.end());
    for( int i = 0; i < ranges.size() - 1; i++ ) {
        if( ranges[i].second >= ranges[i+1].first - 1 ) {
            ranges[i+1].first = ranges[i].first;
            ranges[i+1].second = max(ranges[i].second, ranges[i+1].second);
            ranges[i].first = -1;
            ranges[i].second = -1;
        }
    }

    for( const auto& range : ranges ) {
        if( range.first != -1 ) {
            ans += (range.second - range.first + 1);
        }
    }
    cout << ans << '\n';
}