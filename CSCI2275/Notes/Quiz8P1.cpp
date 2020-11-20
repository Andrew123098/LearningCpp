/*Write a c++ function to implement Breadth First Traversal on a graph. 
This algorithm is similar to the BFS that we covered in class, except that you're not searching for a vertex, 
you traverse the graph until all vertices have been visited. The graph implementation is on Canvas, 
called GraphIntro.zip in the files for Module 3. The function takes a starting vertex as the parameter. 
Whenever a vertex is enqueued, print the vertex.

void Graph::BFTraversal(string startingV);

The vertex structure here includes a "visited" variable, set to false by default. 
You can use this variable in your BFTraversal function.*/

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    bool visited;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
	void BFTraversal(string startingV);
    protected:
    private:
        std::vector<vertex> vertices;

};

void Graph::BFTraversal(string startingV){
    
    int i = 0;
    while(vertices[i].name != startingV){
        i++;
    }
    vertex* root = &vertices[i];
    vertex* temp = new vertex;
    root->visited = true;

    queue<vertex*> queue;
    queue.push(root);

    while(!queue.empty()){
        temp = queue.front();
        std::cout<<temp->name<<std::endl;
        queue.pop();

        for(int i = 0; i < temp->adj.size(); i++){
            if(temp->adj[i].v->visited == false){
                temp->adj[i].v->visited = true;
                queue.push(temp->adj[i].v);
            }
        }

    }
}

int main() {
	Graph g;
        g.addVertex("Boulder");
        g.addVertex("Denver");
        g.addVertex("New Mexico");
        g.addVertex("Texas");
        g.addVertex("New Orleans");
        //edge written to be undirected
        g.addEdge("Boulder", "Denver", 30);
        g.addEdge("Boulder", "New Mexico", 200);
        g.addEdge("Boulder", "Texas", 500);
        g.addEdge("Denver", "Texas", 300);
        g.addEdge("Texas", "New Orleans", 500);
        //{{TEST.testcode}};
	return 0;
}