#include <vector>
#include <string>
#include <limits.h>

using namespace std;

struct vertex;

struct edge {
    vertex *neighbor;
    int weight;
    edge(vertex* verty, int weightIn) {
        neighbor = verty;
        weight = weightIn;
    }
};

struct vertex {
    string value;
    vector<edge*> links;
    int distance = INT_MAX;
    bool visited;
    vertex(string toAdd) {
        value = toAdd;
        visited = false;
    }
};

class Graph {
    private:
        int numNodes = 0;
        vector<vertex*> vertices;
        vertex* getMinNode();
        bool allVisitedCheck();
    public:
        void addVertex(string);
        void addEdge(string, string, int);
        vertex* findVert(string);
        void dijkstra(string);
        void pathBack();
};