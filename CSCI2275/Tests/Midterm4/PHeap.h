#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef PHEAP_H
#define PHEAP_H
struct HeapNode{
    public:
    string name = "";
    int time = -1;
    int treatment = -1;
    HeapNode();
    HeapNode(string n, int t, int p);
};
class PHeap{
    private:
        void swap(int f, int l);
        vector<HeapNode> nodes; // NEW
        void minHeapify(int i);
        int capacity;
        int currentSize;

    public:
        PHeap(int);
        void push(string n, int t, int p);
        HeapNode pop();
};
#endif