#include <bits/stdc++.h>
using namespace std;

bool isValid(long long num) {
    string s = to_string(num);
    int len = s.length();
    for (int patternLen = 1; patternLen <= len / 2; patternLen++) {
        if (len % patternLen != 0) continue;
        string pattern = s.substr(0, patternLen);
        bool isRepeated = true;
        for (int i = patternLen; i < len; i += patternLen) {
            if (s.substr(i, patternLen) != pattern) {
                isRepeated = false;
                break;
            }
        }
        if (isRepeated) return true;
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

    string line;
    getline(in, line);
    in.close();

    stringstream ss(line);
    string interval;

    long long totalSum = 0;

    while(getline(ss, interval, ',')) {
        size_t dashPos = interval.find('-');
        long long start = stoll(interval.substr(0, dashPos));
        long long end = stoll(interval.substr(dashPos + 1));
        
        for(long long i = start; i <= end; i++) {
            if(isValid(i)) {
                totalSum += i;
            }
        }
    }
    cout << totalSum << '\n';
}