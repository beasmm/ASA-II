#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;

unordered_map<int, int> p;

int find(int x) {
    if (p[x] != x) 
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    int total = 0;
    scanf("%d %d", &n, &m);

    // Loop to read the edges
    for (int i = 0; i < m; i++) {
        Edge newEdge;
        cin >> newEdge.u >> newEdge.v >> newEdge.w;
        edges.push_back(newEdge);
    }

    // Sort the edges in decreasing order by weight
    sort(edges.begin(), edges.end(), [](Edge const e1, Edge const & e2) {
        return e1.w > e2.w;
    });

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // Check if adding the edge (u, v) would create a cycle
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            total += w;
            p[pu] = pv;
        }
    }

    cout << total << endl;

    return 0;
}
