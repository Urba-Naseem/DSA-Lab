#include <iostream>
using namespace std;

int recursiveSum(int array[], int size) {
    if (size == 0){
        return 0;
    }
    
    return array[size - 1] + recursiveSum(array, size - 1);
}

int main() {
    int array[] = {15,32,9,27,41};
    int size = sizeof(array) / sizeof(array[0]);
    
    int sum=recursiveSum(array, size);
	cout << "Sum of Array elements: " <<sum<< endl;  // Output: 15
    return 0;
}

