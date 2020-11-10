#include "Graph.h"
#include <iostream>
#include <limits.h>

//return a vertex in the vertices vector, if it exists
vertex* Graph::findVert(string toAdd) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->value == toAdd) {
            return vertices[i];
        }
    }
    return NULL;
}

//add a vertex to the vertices vector
void Graph::addVertex(string toAdd) {
    if (findVert(toAdd) == NULL) {
        vertices.push_back(new vertex(toAdd));
    }
    numNodes++;
}

//if both firstv & secondv are present in the graph, create an edge b/w them 
void Graph::addEdge(string firstv, string secondv, int weight) {
    vertex *fv = findVert(firstv);
    vertex *sv = findVert(secondv);
    if (!fv || !sv) {
        cout << "Either " << firstv << " or " << secondv << " not present in graph." << endl;
    } else {
        //detect duplicate edges (ugly way to do it but alas)
        for (int i = 0; i < fv->links.size(); i++) {
            if (fv->links[i]->neighbor->value == secondv) {
                return;
            }
        }
        edge *egg = new edge(sv, weight);
        fv->links.push_back(egg);
        edge *eggo = new edge(fv, weight);
        sv->links.push_back(eggo);
    }
}

// START OF DIJKSTRAS

//getMinNode() will return the node with the lowest distance that has not yet been visited
vertex* Graph::getMinNode(){
    //loop through vertices and get smallest distance node. (make sure that node has not yet been visited)
    int min = INT_MAX;
    vertex* result;

    for(vertex* v: vertices){
        if(!v->visited){
            if(v->distance < min){
                min = v->distance;
                result = v;
            }
        }
    }
    return result;
} 

//allVisitedCheck() will return true if all nodes have been visited 
bool Graph::allVisitedCheck(){
    //loop through all vertices and check if allVisited is true
    for(vertex* v : vertices){
        if(!v->visited){
            return false;
        }
    }
    return true;
    

    
}

//go through each node and update its distance from the src.
//thus creating a minimum spanning tree where each node has its min distance from the source.
//after making these values print them all
void Graph::dijkstra(string src) { 
    //all nodes start with a value fo INT_MAX. set source node's distance to 0 as a starting point
    vertex* tempSrc = findVert(src);
    tempSrc->distance = 0;

    //While all nodes have not been visited
    //1. get the node with the min distance that has not been visited (use getMinNode())
    //2. set that node visited to true
    //3. update distance of all adjacent vertices of minNode(only if new distance would be smaller)

    while(!allVisitedCheck()){
        vertex* minNode = getMinNode();
        minNode->visited = true;

        for(edge* e : minNode->links){
            if(e->neighbor->distance > minNode->distance + e->weight){
                e->neighbor->distance = minNode->distance + e->weight;
            }
        }
    }

    //print distance to each node
    for(vertex* v : vertices){
        cout<<v->value<<" is "<<v->distance<<" away from the source "<<src<<endl;
    }

    //reset values, distance and visited
    for(vertex* v : vertices){
        v->distance = INT_MAX;
        v->visited = false;
    }

} 
//END OF DIJKSTRAS



void Graph::pathBack() {
    for (vertex* e : vertices) {

        vertex* temp = e;
        while(temp != NULL) {
            
        }
    }
}


int main() {
    Graph myGwaf;
    myGwaf.addVertex("A");
    myGwaf.addVertex("B");
    myGwaf.addVertex("C");
    myGwaf.addVertex("D");
    myGwaf.addVertex("E");
    myGwaf.addVertex("F");
    myGwaf.addVertex("G");
    myGwaf.addVertex("H");
    myGwaf.addVertex("I");
    myGwaf.addVertex("J");
    myGwaf.addVertex("K");
    myGwaf.addEdge("A", "B", 3);
    myGwaf.addEdge("B", "C", 1);
    myGwaf.addEdge("C", "D", 1);
    myGwaf.addEdge("A", "E", 4);
    myGwaf.addEdge("E", "B", 6);
    myGwaf.addEdge("E", "F", 2);
    myGwaf.addEdge("F", "C", 4);
    myGwaf.addEdge("C", "G", 3);
    myGwaf.addEdge("G", "D", 9);
    myGwaf.addEdge("D", "K", 1);
    myGwaf.addEdge("G", "K", 2);
    myGwaf.addEdge("J", "K", 1);
    myGwaf.addEdge("F", "J", 4);
    myGwaf.addEdge("I", "J", 1);
    myGwaf.addEdge("E", "I", 7);
    myGwaf.addEdge("H", "E", 4);
    myGwaf.addEdge("H", "I", 1);
    myGwaf.dijkstra("A");
}