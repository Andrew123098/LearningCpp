#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    // //another vertex for edge in other direction
                    // adjVertex av2;
                    // av2.v = &vertices[i];
                    // av2.weight = weight;
                    // vertices[j].adj.push_back(av2);
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
        v.groupID = -1;
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

int Graph::isAdjacent(std::string v1, std::string v2){
/* Finds whether or not there is a path from one vertex to the other 
and returns the distance between them.*/
    vertex *root = findVertex(v1);           // Find if the vertex exists in the graph and store in root pointer.
    int distance = 0;                        // Variable for distance between the two vertices.

    stack<vertex*> stack;                    // Create stack of vertex pointers.
    stack.push(root);                        // Push root onto the stack.
    unvisit();

    while(!stack.empty()){                   // While the stack is not empty ...
        vertex* tempV = stack.top();         // Store the top of the stack in a temp pointer.
        stack.pop();                         // Pop the top of the stack.

        vertex *v = findVertex(tempV->name); // Find the top value in the stack in the graph.
        if(v->visited == false){             // If that vertex has not yet been visited ...
            if(v->name == v2){               // If that vertex's name is equal to v2 ...
                unvisit();                   // Make all values unvisited.
                while(v->name != root->name){
                    distance+=v->distance;
                    v = v->parent;
                }
                return distance;             // Return the distance between the two vertices.  
            }                                // If name is not equal to v2 ...
            v->visited = true;               // Set visited to true.
        }                          
        for(adjVertex edge : v->adj){        // Loop through all adjacent vertices.
            if(edge.v->visited == false){    // If the vertex has not been visited yet ...
                edge.v->distance = edge.weight; 
                edge.v->parent = v;
                stack.push(edge.v);          // Push that vertex onto the stack.
            } 
        }
    }

    unvisit();                               // Mark all vertices as unvisited.
    cout<<"There is no connection between "<<v1<<" and "<<v2<<endl;
    return distance;                         // Return the distance between the two vertices.
}

void Graph::assignGroupID(){
/* Start at first vertex and assign it and all adjacent vertices a unique group ID.
Find the next vertex w/o an ID and do the same until all vertices have group IDs. */
    int ID = 1;                         // Unique ID for each group.
    for(vertex v : vertices){           // Loop through all vertices in vertices vector.
        if(v.groupID == -1){            // If the group ID has not yet been set ...
            cout<<"Group #"<<ID<<":";   // Print group number.
            DFSLabel(v.name, ID);       // Call the labeler function for the group.
            cout<<endl;                 
            ID++;                       // Increment ID so they are all unique.
        }
    }
    unvisit();                          // Return all the visited booleans to false.
}

void Graph::infectAndTrace(){
/* Select a person randomly and change their infected state to true. 
Find all adjacent vertices with whom they have had close contact (weight > 15).
Print the name of the infected person, all of their contacts, and how long they spend together. */

    int closeContact = 15;                                   // Time in minutes that is considered close contact.
    int vertexNum = rand() %vertices.size();                 // Generate Random person.
    vertex* infected = &vertices[vertexNum];                 // Pointer to infected individual.
    infected->infected = true;                               // Set random person's infected status to true.

    stack<vertex*> atRisk;                                   // Create stack to store at rik individuals who have been in close contact with the infected individual.

    cout<<"Infected: "<<infected->name<<endl;                // Print the infected.
    cout<<"Close contacts: "<<endl;                          // List their close contacts.
    for(adjVertex edge : infected->adj){                     // Loop through all contacts.
        cout<<edge.v->name<<","<<edge.weight<<endl;          // Print the contacts and their time spent with the infected individual.
        if(edge.weight > closeContact){                      // If they have been in close contact with the infected individual ...
            atRisk.push(edge.v);                             // Add them to the stack.
        }
    }
}

void Graph::infectAndSpread(double rate){
/* Prompt the user to enter an infection rate from 0-1. 
Select a person randomly and set their infection status to true.
Identify all individuals with whom the infected individual has been in close contact 
and use the infection rate to change their infected status to true.
Once an individual is infected, add them to the queue and repeat the process for their close contacts.
The infection rate should be cut in half with each stap away from the initial infection.
Repeat until the queue is empty. */

    int closeContact = 15;                                   // Time in minutes that is considered close contact.
    int vertexNum = rand() %vertices.size();                 // Generate Random person.
    double originalRate = rate;
    vertex* infected = &vertices[vertexNum];                 // Pointer to infected individual.
    vertex* root = &vertices[vertexNum];                     // Pointer to root infected individual.
    infected->infected = true;                               // Set random person's infected status to true.
    infected->visited = true;                                // Set random person's visited status to true.
    cout<<"Original Contractor: "<<root->name<<endl;

    queue<vertex*> infectedQ;                                // Queue to store infected individuals.
    infectedQ.push(infected);                                // Enqueue OG infected into the queue
    
    while(!infectedQ.empty()){                               // While the infected queue is not empty ...
        infected = infectedQ.front();                        // Get the top value from the queue.
        infectedQ.pop();                                     // Remove that value from the queue.
        for(int i = 0; i < infected->adj.size(); i++){       // Loop through all the adjacent people to the infected.
            if(infected->adj[i].v->visited == false){        // If we have not yet visited the vertex ...
                int df = 0;                                  // Stores degrees of freedom from the root.
                rate = originalRate;                         // Reset the rate for recalculation. 
                adjVertex* adjacent = &infected->adj[i];     // Points to the current adjacent value we are on.
                adjVertex temp = infected->adj[i];           // Copy of the adjacent vertex for looping.
                adjacent->v->parent = infected;              // Set the adjacent vertex's parent value to its parent vertex.
                while(temp.v->name != root->name){           // Find the degrees of freedom from the root.
                    df++;                                    // Incrememnt degrees of freedom.
                    temp.v = temp.v->parent;                 // Move to parent vertex.
                }
                df--;                                        // Subtract 1 from the df b/c math.
                if(df < 0)                                   // But make sure if we are at the root or the roots adjacents ...
                    df = 0;                                  // They have the same infection rate.
                rate/=(pow(2,df));                           // Change rate based on degrees of freedom from the root. 
                if(adjacent->weight > closeContact){         // If the time pent with the infected individual is considered "close contact" ...
                    double infectionChance = ((double) rand() / (RAND_MAX)); // Generate number b/w 0 and 1.
                    if (infectionChance < rate){             // And if the generated number is below the rate ...
                        adjacent->v->infected = true;        // Set the vertex's infected value to true.
                        adjacent->v->visited = true;         // Set the visited status to true so we do not visit it again.
                        infectedQ.push(adjacent->v);         // Push this vertex onto the infected Q so we can test its adjacents.
                        cout<<"Infected "<<adjacent->v->name<<" after spending "<<adjacent->weight<<" minutes with "<<adjacent->v->parent->name<<endl;
                    }
                }
            }
        }
    } 
}

vertex *Graph::findVertex(std::string name){
/* Return a vertex in the vertices vector if it exists in the graph */
    for (int i = 0; i < vertices.size(); i++) {  // Loop through each vertex in the vertices vector.
        if (vertices[i].name == name) {          // If the vertex value is equal to the given input ...
            return &vertices[i];                 // Return Pointer to vertex.
        }
    }
    return NULL;                                 // Return NULL.
}

void Graph::DFSLabel(std::string person, int ID){
/* Call in assignGroupID to run FS from a specific vertex. 
Pass in a group ID and every vertex DFSLabel visits will get that same group ID */
    vertex* root = findVertex(person); // Get pointer to root vertex with the given name.
    if (root != NULL) {                // If the root is not NULL ...
        DFSLabelHelper(root, ID);      // Call the helper to DFS through the root's connected vertices.
    } else {                           // Otherwise ...
        cout<<"Root is NULL"<<endl;    // Print Error statement.
    }
    cout << endl;
}

void Graph::DFSLabelHelper(vertex *inV, int ID) {
/* Helper Function: DFS through all connected vertices and assign them a group ID */
    inV->visited = true;                         // Set visited to true.              
    inV->groupID = ID;                           // Set their ID to the current group ID.
    cout<<" "<<inV->name<<",";                   // Print the name of the vertex.
    vertex *temp;                                // Pointer to move through all adjacent vertices.
    for (int i = 0; i < inV->adj.size(); i++) {  // Loop through all adjacent vertices.
        temp = inV->adj[i].v;                    // Set temp equal to the adjacent vertex's pointer to the vertex in the vertices vector.
        if(!temp->visited){                      // If vertex has not been visited yet ...
            DFSLabelHelper(temp, ID);            // Recursively call the helper with temp
        }
    }
}

void Graph::unvisit() {
/* Marks all verices in the graph as unvisisted */
    for (int i = 0; i < vertices.size(); i++) {  // Loop through all vertices.
        vertices[i].visited = false;             // Set all vertices visited value to false.
    }
}

void Graph::uninfect() {
/* Marks all verices in the graph as unvisisted */
    for (int i = 0; i < vertices.size(); i++) {  // Loop through all vertices.
        vertices[i].infected = false;            // Set all vertices infected value to false.
    }
}