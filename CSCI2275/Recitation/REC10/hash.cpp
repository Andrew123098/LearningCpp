// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
//Compute the index by using the hash function
node* HashTable::searchItem(int key)
{
    int index = hashFunction(key);
    node* temp = table[index];
    while(temp){
        if(temp->key == key){
            return table[index];
        }
        temp = temp->next;
    }
    return NULL;     
}

//TODO Complete this function
//function to insert
// TODO :
// Use the hash function on the key to get the index/slot,
// create a new node with the key and insert it in this slot's list
bool HashTable::insertItem(int key)
{
    if(!searchItem(key)){
        int index = hashFunction(key);
        node* temp = table[index];
        node* insert = new node;
        insert->key = key;
        insert->next = NULL;
        if(temp){
            while(temp->next){
                temp = temp->next;
            }
            temp->next = insert;
        } else { // no collision
            table[index] = insert;
        }

    } else {
        cout<<"duplicate entry"<<endl;
        return false;
    }
    return true;
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for(int i = 0; i < tableSize; i++){
        cout<<i<<" || ";
        node* temp = table[i];
        while(temp){
            cout<<temp->key<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

}