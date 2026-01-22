//
// pch.cpp
//

#include "pch.h"

using namespace std;

Graph::Graph(int number) {
    numberOfVertexes = number;
    matrix = new int* [numberOfVertexes];
    for (size_t i = 0; i < numberOfVertexes; i++) matrix[i] = new int[numberOfVertexes];
    for (size_t i = 0; i < numberOfVertexes; i++) for (size_t j = 0; j < numberOfVertexes; j++) matrix[i][j] = 0;
}

void Graph::addEdge(int u, int v, int w) {
    matrix[u][v] = w;
    matrix[v][u] = w;
}

void Graph::removeEdge(int u, int v) {
    matrix[u][v] = 0;
    matrix[v][u] = 0;
}

void Graph::print() {
    cout << "Adjacency matrix \n\n";
    for (int i = 0; i < numberOfVertexes; i++) {
        cout << i << " : ";
        for (int j = 0; j < numberOfVertexes; j++) {
            cout << '\t' << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

size_t Graph::getNumberOfVertexes() {
    return numberOfVertexes;
}

bool Graph::areConnected(size_t i, size_t j) {
    return matrix[i][j] != 0;
}

int*& Graph::operator[](size_t i) {
    return matrix[i];
}

Dijkstra::Dijkstra(Graph ggraph) : graph(ggraph) {
    marked = new bool[graph.getNumberOfVertexes()];
    fromAr = new int[graph.getNumberOfVertexes()];
    pathLength = new int[graph.getNumberOfVertexes()];
    init();
}

void Dijkstra::init() {
    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        marked[i] = false;
        fromAr[i] = -1;
        pathLength[i] = 0;
    }
}

void Dijkstra::recalculateLengthFromMarked() {
    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        if (marked[i]) {
            for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
                if (!marked[j] && graph[i][j] != 0) {
                    int newLength = pathLength[i] + graph[i][j];
                    if (newLength < pathLength[j] || pathLength[j] == 0) {
                        pathLength[j] = newLength;
                        fromAr[j] = i;
                    }
                }
            }
        }
    }
}

void Dijkstra::markShortest() {
    int minLength = INT_MAX;
    int ind = -1;
    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        if (!marked[i]) {
            if ((pathLength[i] < minLength) && pathLength[i] != 0) {
                minLength = pathLength[i];
                ind = i;
            }
        }
    }
    if (ind != -1) marked[ind] = true;
}

void Dijkstra::fillWay(size_t from, size_t to, vector<int>& way) {
    way.push_back(to);
    while (to != from) {
        way.push_back(fromAr[to]);
        to = fromAr[to];
    }
}

int Dijkstra::findWay(size_t from, size_t to, vector<int>& way) {
    init();
    marked[from] = true;
    while (!marked[to]) {
        recalculateLengthFromMarked();
        markShortest();
    }
    fillWay(from, to, way);
    return pathLength[to];
}

int main(/*int argc, char** argv*/) {
    // Creating a graph and adding edges
 /*   Graph graph(8);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 4, 3);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 4, 3);
    graph.addEdge(2, 5, 1);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 6, 2);
    graph.addEdge(3, 7, 7);
    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 6, 5);
    graph.addEdge(6, 7, 4);*/

   Graph graph(4);
   graph.addEdge(0, 1, 3 );
   graph.addEdge(0, 2, 1);
   graph.addEdge(0, 3, 2);
   graph.addEdge(1, 2, 2);
   graph.addEdge(2, 3, 1);
   
    // Printing the adjacency matrix of the graph
    graph.print();

    // Finding the shortest path using Dijkstra's algorithm
    vector<int> way;
    Dijkstra algorithm(graph);
    int shortestPathLength = algorithm.findWay(0, 2 , way);
    cout << endl << "Shortest path length from vertex 0 to vertex 2: " << shortestPathLength << endl;
    cout << "Shortest path: ";
    for (auto it = way.rbegin(); it != way.rend(); ++it) {
        if (it != way.rbegin()) cout << " -> ";
        cout << *it;
    }
    cout << endl;

    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
}


