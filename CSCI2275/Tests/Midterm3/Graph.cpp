#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

vertex* Graph::search(string v){
    for(int x = 0; x < vertices.size(); x++){
        if (vertices[x].name == v){
            return &vertices[x];
        }
    }
    return nullptr;
}


vertex* Graph::BFS(string startVal, string endVal){
    for(int x = 0; x < vertices.size(); x++){
        vertices[x].visited = false;
        vertices[x].distance = 0;
        vertices[x].parent = nullptr;
    }
    //search for startVal
    vertex *v = search(startVal);
    v->visited = true;
    v->distance = 0;
    v->parent = nullptr;
    //add v to a queue
    queue<vertex*> q;
    q.push(v);
    while(!q.empty()){
        vertex *n = q.front(); //front returns a value
        q.pop(); //pop removes from queue
        for(int x = 0; x < n->adj.size(); x++){
            if(n->adj[x].v->visited == false){
                n->adj[x].v->distance = n->distance + 1; //parent distance + 1
                n->adj[x].v->parent = n;
                //check if it's what we're looking for
                if(n->adj[x].v->name == endVal){
                    return n->adj[x].v; 

                }else{
                    n->adj[x].v->visited = true;
                    q.push(n->adj[x].v);
                }
            }
        }
    }
    return nullptr;
}

