#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distances[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        int current = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(current > distances[u]) continue;

        for(const Edge& e : G[u]){
            int v = e.dst;
            int weight = e.weight;

            if(distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}


vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    stack<int> s;
    vector<int> path;
    for (int i = destination; i != -1; i = previous[i]) {
        s.push(i);
    }
    while (!s.empty()) {
        path.push_back(s.top());
        s.pop();
    }
    return path;
}


void print_path(const vector<int>& v, int total) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\nTotal cost: " << total << endl;
}

int calculate_total(vector<int> v){
    int total = 0;
    for(int i : v) total+=i;
    return total;
}