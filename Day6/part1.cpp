#include <bits/stdc++.h>
using namespace std;

long long calculate(const vector<vector<int>>& numbers, const vector<string>& ops) {
    long long ans = 0;
    int n = numbers.size();
    int m = numbers[0].size();
    int idx = 0;
    for(int i = 0; i < m; i++){
         if(ops[idx] == "+") {
            long long sum = 0;
            for(int j = 0; j < n; j++){
                sum += numbers[j][i];
            }
            ans += sum;
         }
         else if(ops[idx] == "*") {
            long long prod = 1;
            for(int j = 0; j < n; j++){
                prod *= numbers[j][i];
            }
            ans += prod;
         }
         idx++;
    }
    return ans;
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;
    vector<vector<int>> numbers;
    vector<string> ops;
    long long ans = 0;
    while(getline(in, line)) {
        stringstream ss(line);
        string word;
        vector<int> row;
        while(ss >> word) {
            if(word == "+" || word == "*") {
                ops.push_back(word);
            }
            else row.push_back(stoi(word));
        }
        if(!row.empty()) numbers.push_back(row);        
    }
    ans = calculate(numbers, ops);
    cout << ans << '\n';
}