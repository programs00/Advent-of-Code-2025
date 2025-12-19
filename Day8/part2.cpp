#include<bits/stdc++.h>
using namespace std;

using ll = long long;


struct Point {
    ll x;
    ll y;
    ll z;
};

struct Conn {
    int u;
    int v;
    double dist;
};

struct Graph {
    vector<int> parent, sz;

    Graph(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int a) {
        if(parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];;
        return true;
    }
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

int main() {
    const string fileName = "in";

    ifstream in(fileName);
    if(!in) {
        cout << "File not found: " << fileName << '\n';
        return 1;
    }

    string line;

    vector<Point> coords;
    
    while(getline(in, line)) {
        stringstream ss(line);
        string coo;

        vector<ll> coordTuple;
        while(getline(ss, coo, ',')) {
            coordTuple.push_back(stoll(coo));
        }
        coords.push_back(Point{coordTuple[0], coordTuple[1], coordTuple[2]});
    }

    int n = coords.size();
    vector<Conn> connections;

    for(int i = 0; i < n; i++){ 
        for(int j = i+1; j < n; j++){
            double dist = distance(coords[i], coords[j]);
            connections.push_back(Conn{i, j, dist});
        }
    }

    sort(connections.begin(), connections.end(),
        [](const Conn& a, const Conn& b) {
            return a.dist < b.dist;
        });

    int m = connections.size();

    int temp = n;
    Conn lastConn;
    Graph g(n);
    for(int i = 0; i < m; i++) {
        if(g.unite(connections[i].u, connections[i].v)) {
            temp--;
            lastConn = connections[i];
            if(temp == 1) break;
        }
    }

    long long result = coords[lastConn.u].x * coords[lastConn.v].x;
    cout << result << '\n';
}