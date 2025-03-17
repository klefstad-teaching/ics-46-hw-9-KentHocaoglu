#include "dijkstras.h"

using namespace std;

int main() {

    Graph G;
    file_to_graph("src/small.txt", G);
    int source = 0;
    int destination = 2;

    vector<int> previous(G.size(), -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> paths = dijkstra_shortest_path(G, source, previous);
    print_path(paths, calculate_total(paths));
    vector<int> path = extract_shortest_path(distances, previous, destination);
    print_path(path, calculate_total(path));

    return 0;
}





