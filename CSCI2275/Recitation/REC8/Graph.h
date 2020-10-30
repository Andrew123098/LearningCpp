#include <vector>
#include <string>

using namespace std;

struct vertex;

struct edge {
    vertex *neighbor;
    edge(vertex* verty) {
        neighbor = verty;
    }
};

struct vertex {
    string value;
    vector<edge*> links;
    bool visited;
    vertex(string toAdd) {
        value = toAdd;
        visited = false;
    }
};

class Graph {
    private:
        vector<vertex*> vertices;
    public:
        void addVertex(string);
        void addEdge(string, string);
        vertex* findVert(string);
        void dfsR(string);
        void dfsI(string); //todo together
        bool isThereAPath(string, string); //todo
        void unvisit(); //todo
        void print();
};