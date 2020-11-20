#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
    bool visited = false;
    int distance = 0;
    vertex *parent = nullptr;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        vertex* search(std::string v);

    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;
        vertex* BFS(std::string v1, std::string v2);

};

#endif // GRAPH_H
