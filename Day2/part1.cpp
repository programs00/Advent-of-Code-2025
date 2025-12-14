#include <bits/stdc++.h>
using namespace std;

bool isValid(long long num) {
    string s = to_string(num);
    int n = s.size();

    if (n%2 != 0) return false;

    int half = n / 2;
    string first = s.substr(0, half);
    string second = s.substr(half);

    return first == second;
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