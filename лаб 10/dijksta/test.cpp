#include "pch.h"

TEST(GraphTest, AddEdge) {
    Graph graph(5);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 3);

    bool edge01 = graph.areConnected(0, 1);
    bool edge12 = graph.areConnected(1, 2);

    EXPECT_TRUE(edge01);
    EXPECT_TRUE(edge12);
}

TEST(GraphTest, RemoveEdge) {
    Graph graph(5);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 3);
    graph.removeEdge(0, 1);
    EXPECT_FALSE(graph.areConnected(0, 1));
}

TEST(DijkstraTest, ShortestPath) {
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 20);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 3, 15);

    Dijkstra dijkstra(graph);
    vector<int> path;
    int shortestPathLength = dijkstra.findWay(0, 3, path);

    EXPECT_EQ(shortestPathLength, 30); 
    EXPECT_EQ(path.size(), 4); 
    EXPECT_EQ(path[0], 3);
    EXPECT_EQ(path[1], 2);
    EXPECT_EQ(path[2], 1);
}

TEST(GraphTest, GetNumberOfVertexes) {
    Graph graph(10);

    EXPECT_EQ(graph.getNumberOfVertexes(), 10);
}
TEST(GraphTest, AreConnected) {
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 5);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 3);

    EXPECT_TRUE(graph.areConnected(0, 1));
    EXPECT_TRUE(graph.areConnected(1, 2));
    EXPECT_TRUE(graph.areConnected(2, 3));
    EXPECT_TRUE(graph.areConnected(3, 4));

    EXPECT_FALSE(graph.areConnected(0, 2));
    EXPECT_FALSE(graph.areConnected(1, 3));
    EXPECT_FALSE(graph.areConnected(2, 4));
}

