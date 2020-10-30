#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

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
}

//if both firstv & secondv are present in the graph, create an edge b/w them 
void Graph::addEdge(string firstv, string secondv) {
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
        edge *egg = new edge(sv);
        fv->links.push_back(egg);
        edge *eggo = new edge(fv);
        sv->links.push_back(eggo);
    }
}

//print all of the vertices in a graph & their neighbors
void Graph::print() {
    vertex *lilvert;
    for (int i = 0; i < vertices.size(); i++) {
        lilvert = vertices[i];
        cout << lilvert->value << ": ";
        for (int j = 0; j < lilvert->links.size(); j++) {
            cout << lilvert->links[j]->neighbor->value << " ";
        }
        cout << endl;
    }
}

//recursively traverse down the tree from the given vertex
//and print it very badly
void dfsRHelper(vertex *inV) {
    inV->visited = true;
    vertex *temp;
    for (int i = 0; i < inV->links.size(); i++) {
        temp = inV->links[i]->neighbor;
        if (!temp->visited) {
            cout << temp->value << endl;
            dfsRHelper(temp);
        }
    }
}

void Graph::dfsR(string value) {
    vertex *root = findVert(value);
    if (root != NULL) {
        cout << endl << root->value << endl;
        dfsRHelper(root);
    }
    cout << endl;
    // unvisit();
}

//iteratively traverse through a graph from the given vertex
void Graph::dfsI(string value) {
    vertex *root = findVert(value);
    stack<string> stack; //cn be done with vactors as well
    stack.push(value); // Push value to the top of the stack

    while(!stack.empty()){ // Run while the stack is not empty
        string v1 = stack.top(); // Return the top value in the stack
        stack.pop(); // Then remove that value from the top of the stack

        vertex *v = findVert(v1); //Get the vertex returned by the string
        if(v->visited == false){ // If it hasnt been visited.
            cout<<v->value<<endl; // Print the value of the vertex
            v->visited = true; // Mark the vertex as visited
        }

        for(edge *edge : v->links){ //loops through the array "v->links" which is a vector of edges with the edge pointer
            if(edge->neighbor->visited == false){ // if we have not yet visited the neighbor...
                stack.push(edge->neighbor->value); // move that neighbor into the stack
            }
        }
    }
    unvisit();
}

void Graph::unvisit() {
// TODO: marks all verices in the stack as unvisisted
vertex *lilvert;
    for (int i = 0; i < vertices.size(); i++) {
        lilvert = vertices[i];
        lilvert->visited = false;
        // for (int j = 0; j < lilvert->links.size(); j++) {
        //     lilvert->links[j]->neighbor->visited = false;
        // }
    }

}

bool Graph::isThereAPath(string v1, string v2){
    vertex *root = findVert(v1);

    stack<string> stack;
    stack.push(v1);

    while(!stack.empty()){
        string tempV = stack.top();
        stack.pop();

        vertex *v = findVert(tempV);
        if(v->visited == false){
            if(v->value == v2){
                unvisit();
                return true;
            }
            v->visited = true;
        }
        for(edge* edge : v->links){
            if(edge->neighbor->visited == false){
                stack.push(edge->neighbor->value);
            }
        }
    }
    unvisit();
    return false;
}

int main() {
    // g++ -std=c++11 Graph.cpp -o Graph
    // ./Graph

    Graph myGwaf;
    myGwaf.addVertex("A");
    myGwaf.addVertex("B");
    myGwaf.addVertex("C");
    //myGwaf.addVertex("D");
    //myGwaf.addVertex("E");
    myGwaf.addEdge("A", "B");
    myGwaf.addEdge("A", "C");
    myGwaf.addEdge("B", "C");
    //myGwaf.addEdge("D", "E");
    myGwaf.print();
    //myGwaf.isThereAPath("A", "C"); //should pass
    //myGwaf.isThereAPath("A", "D"); //should fail
    myGwaf.dfsI("A");
    cout<<myGwaf.isThereAPath("A", "B")<<endl;
    cout<<myGwaf.isThereAPath("A", "D")<<endl;



}