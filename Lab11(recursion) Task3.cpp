#include <iostream>
using namespace std;

int recursiveLinearSearch(int array[], int size, int find, int index = 0) {
	
    if (index == size){
        return -1;
    }

    if (array[index] == find){
        return index;
    }

    return recursiveLinearSearch(array, size, find, index + 1);
}

int main() {
    int array[] = {23, 71, 99, 51, 16, 48, 35, 86};
    int size = sizeof(array) / sizeof(array[0]);
    
    int find;
    cout << "Enter the number to search: ";
    cin >> find;
    
    cout<<"=========================================\n"<<endl;
    int answer = recursiveLinearSearch(array, size, find);

    if (answer != -1){
        cout << "Number "<<find<<" found at index " << answer <<"! :)" << endl;
    }
	else{
        cout << "Number "<<find<<" not found in the array! :(" << endl;
    }
    
    return 0;
}

