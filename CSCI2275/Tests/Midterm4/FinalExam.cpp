// On line 64 of PHeap.cpp, trying to access spot in nodes array that never has space allocated for it. So I made nodes a vector and allocated space for it.
// On line 45 of FinalExam.cpp, not enough space allocated for people in CSV. Changed capacity from 100 to 882.
// On line 90 of PHeap.cpp, should be returning the original head, not the new head after a minHeapify.
// On line 67 of PHeap.cpp, we need to compare the 2 time values, not the time value to the treatment value.
// On line 71 of PHeap.cpp, we need to have this be a while loop, not an if statement so that all people with the same time values are taken into account.
// On line 73 of PHeap.cpp, we need to divide i by 2 so the while loop is not infinite.

#include "PHeap.h"
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;
struct defaultPerson{
    public:
    string name;
    int time;
    int treatment;
    defaultPerson(string n, int t, int tr)
    {
        name = n;
        time = t;
        treatment = tr;
    }
};
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << argc;
        return 0;
    }
    ifstream file;
    file.open(argv[1]);
    vector<defaultPerson> people;
    string line;
    getline(file, line);
    while (getline(file, line))
    {
        stringstream data(line);
        string word;
        string time;
        string treatment;
        getline(data, word,',');
        getline(data, time,',');
        getline(data,treatment,',');
        people.push_back(defaultPerson(word, stoi(time), stoi(treatment)));
    }
    PHeap heap(882); // NEW
    for(int i = 0; i < people.size(); i++)
    {
        heap.push(people[i].name, people[i].time, people[i].treatment);
    }
    for(int x = 0; x < people.size(); x++)
    {
        HeapNode temp;
        temp = heap.pop();
        cout<<temp.name<<" "<<temp.time<<endl;
    }
}