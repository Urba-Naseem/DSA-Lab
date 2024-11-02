#include <iostream>
using namespace std;

int binaryRecursiveSearch(const int array[], int left, int right, int target) {
  
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (array[mid] == target) {
        return mid; 
    }

    if (target < array[mid]) {
        return binaryRecursiveSearch(array, left, mid - 1, target);
    }

    return binaryRecursiveSearch(array, mid + 1, right, target);
}

int main() {
    
    const int array[] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45};
    
    int size = sizeof(array) / sizeof(array[0]);

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    cout<<"=========================================\n"<<endl;
    int answer = binaryRecursiveSearch(array, 0, size - 1, target);

    if (answer != -1){
        cout << "Number "<<target<<" found at index " << answer <<"! :)" << endl;
    }
	else{
        cout << "Number "<<target<<" not found in the array! :(" << endl;
    }

    return 0;
}
