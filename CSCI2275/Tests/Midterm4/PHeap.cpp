#include "PHeap.h"
using namespace std;
HeapNode::HeapNode(string n, int t, int p)
{
    name = n;
    time = t;
    treatment = p;
}
HeapNode::HeapNode()
{
    
}
void PHeap::swap(int f, int l)
{
    if(currentSize < f || currentSize < l)
    {
        cout << "Arguments outside range\n";
        return;
    }
    HeapNode temp = nodes[f];
    nodes[f] = nodes[l];
    nodes[l] = temp;
}
void PHeap::minHeapify(int i)
{
    int min = i;
    int left = 2*i;
    int right = (2*i) + 1;
    if(left < currentSize && nodes[min].time > nodes[left].time)
    {
        min = left;
    }
    else if(left < currentSize && nodes[min].time == nodes[left].time && nodes[min].treatment > nodes[left].treatment)
    {
        min = left;
    }
    if(right < currentSize && nodes[min].time > nodes[right].time)
    {
        min = right;
    }
    else if(right < currentSize && nodes[min].time == nodes[right].time && nodes[min].treatment > nodes[right].treatment)
    {
        min = right;
    }
    if(min != i)
    {
        swap(i,min);
        minHeapify(min);
    }
}
PHeap::PHeap(int cap)
{
    capacity = cap;
    currentSize = 0;
    for(int i = 0; i < cap; i++){   // NEW
        nodes.push_back(HeapNode());
    }
}
void PHeap::push(string n, int t, int p)
{
    currentSize++;
    int i = currentSize;
    HeapNode *hn = new HeapNode(n, t, p);
    nodes[i].name = n;
    nodes[i].time = t;
    nodes[i].treatment = p;
    while(nodes[i].time < nodes[(int)i/2].time){  // NEW
        swap(i, (int)i/2);
        i = i / 2;
    }
    while(nodes[i].time == nodes[(int)i/2].time && nodes[i].treatment < nodes[(int)i/2].treatment){ // NEW
        swap(i,(int)i/2);
        i = i/2; // NEW
    }
    
}
HeapNode PHeap::pop()
{
    if(currentSize==0)
    {
        cout<<"Heap empty"<<endl;
        return nodes[0];
    }else if(currentSize==1){
        currentSize--;
        return nodes[1];
    }else{
        HeapNode head = nodes[1];
        nodes[1] = nodes[currentSize];
        currentSize--;
        minHeapify(1);
        return head; // NEW
    }

}
