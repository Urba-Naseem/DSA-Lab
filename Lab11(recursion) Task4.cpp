#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1 || n==0)
       return 1;
        
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout<<"Enter a non-negative number to calculate factorial: ";
    cin>>num;
    
    cout<<"===================================================\n"<<endl;
    if (num < 0) {
    cout << "Factorial is not defined for negative numbers." << endl;
    } 
    else{
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    }
	return 0;
}

