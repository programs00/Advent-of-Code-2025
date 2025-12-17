#include <bits/stdc++.h>
using namespace std;

vector<long long> nums;

void getNumbers(const vector<string>& ops) {
    int n = ops.size() - 1;
    int m = ops[0].size();
    char op;
    long long sum = 0;
    long long prod = 1;
    for(int i = 0; i < m; i++){
        long long value = 0;
        if(ops[n][i] == '+' || ops[n][i] == '*') {
            op = ops[n][i];
            if(op == '+') sum = 0;
            else if(op == '*') prod = 1;
        }
        int count = 0;
        int j;
        for(j = 0; j < n; j++){
            if(ops[j][i] == ' ') {
                count++;
                if(count == n ){
                    if(op == '+') nums.push_back(sum);
                    else if(op == '*') nums.push_back(prod);
                }
                continue;
            }
            value = value * 10 + (ops[j][i] - '0');
        }
        if(op == '+') sum += value;
        else if(op == '*') prod *= value;
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
    vector<string> ops;
    long long ans = 0;
    while(getline(in, line)) {
        ops.push_back(line);
    }
    getNumbers(ops);
    for(auto x : nums) {
        ans += x;
    }
    cout << ans << '\n';
}
