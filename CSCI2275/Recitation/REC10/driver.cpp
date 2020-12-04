// Driver program
#include<iostream>
#include "hash.hpp"
using namespace std;

// Optional Complete this function
//HashTable ht;

// void printPairs(int* arr, int size, int sum, HashTable ht){
//   bool pairFound = false;
//   for int i = 0; i < size; i++){
//     node* temp = ht.searchItem(sum-arr[i]);
//     while(temp){
//       if(temp->key == sum-arr[i]){
//         cout<<"Pairs Found"<<endl;
//         cout<<arr[i]<<" + "<<temp->key<<" = "<<sum<<endl;
//         return NULL;
//       }
//       temp = temp->next;
//     }
//   }
// }



int main()
{
    int a[] = {15, 11, 27, 8, 12, 7, 18};
    int n = 7;

    // 7 is count of buckets in hash table
    HashTable ht(7);

    // insert the keys into the hash table.
    // SILVER TODO : Complete insertItem() function
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }

    cout<< "Contents of the hash table are"<<endl;
    // SILVER TODO : Complete printTable() function
    ht.printTable();

    cout<<endl;

    int searchFor = 8;
    // SILVER TODO : Complete searchItem() function
    if(ht.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }
    cout<<"------------------------------------"<<endl;

    int sum = 19;

    // GOLD TODO Complete printPairs() function
    //printPairs(a,n,sum,ht);

    return 0;
}
