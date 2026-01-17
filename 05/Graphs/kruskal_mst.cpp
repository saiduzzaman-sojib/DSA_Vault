#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int i, vector<int>& parent) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (Edge e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mstWeight += e.weight;
            mstEdges.push_back(e);
            unionSets(e.u, e.v, parent, rank);
        }
    }

    cout << "Weight of MST: " << mstWeight << endl;
    return 0;
}
