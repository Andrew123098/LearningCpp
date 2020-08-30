// Given a 2d array of size N*N (Where N==3 for this case). Return the summ of the largest row (of integers).
#include <iostream>

int findMaxSumArray(int arr[3][3]){
    int sum = 0;
    for(int i=0 ; i<3 ; i++){
        int tempSum = 0;
        for(int j=0 ; j<3 ; j++){
            tempSum = tempSum + arr[i][j];
        }
        if(tempSum > sum){
            sum = tempSum;
        }
    }
    return sum;
}

using namespace std;

int main() {
    int arr[3][3] = {{1,2,3}, {2,3,4}, {5,6,7}};
    int maxVal = findMaxSumArray(arr);
    cout << maxVal << endl;

    return 0;
}