#include <iostream>
#include <string>
using namespace std;

class EmployeeNode {
public:
    int employeeNumber;
    string name;
    double salary;
    EmployeeNode* left;
    EmployeeNode* right;

    // Constructor to initialize an employee node
    EmployeeNode(int empNo, string empName, double empSalary) {
        employeeNumber = empNo;
        name = empName;
        salary = empSalary;
        left = right = NULL;
    }
};

class EmployeeBST {
public:
    EmployeeNode* root;

    // Constructor
    EmployeeBST() {
        root = NULL;
    }

    // Insert a new employee
    EmployeeNode* insert(EmployeeNode* node, int empNo, string empName, double empSalary) {
        if (node == NULL)
            return new EmployeeNode(empNo, empName, empSalary);

        if (empNo < node->employeeNumber)
            node->left = insert(node->left, empNo, empName, empSalary);
        else if (empNo > node->employeeNumber)
            node->right = insert(node->right, empNo, empName, empSalary);

        return node;
    }

    // Search for an employee by employee number
    EmployeeNode* search(EmployeeNode* node, int empNo) {
        if (node == NULL || node->employeeNumber == empNo)
            return node;

        if (empNo < node->employeeNumber)
            return search(node->left, empNo);
        else
            return search(node->right, empNo);
    }

    // Delete an employee by employee number
    EmployeeNode* deleteNode(EmployeeNode* node, int empNo) {
        if (node == NULL)
            return node;

        if (empNo < node->employeeNumber)
            node->left = deleteNode(node->left, empNo);
        else if (empNo > node->employeeNumber)
            node->right = deleteNode(node->right, empNo);
        else {
            if (node->left == NULL) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }

            EmployeeNode* temp = findMin(node->right);
            node->employeeNumber = temp->employeeNumber;
            node->name = temp->name;
            node->salary = temp->salary;
            node->right = deleteNode(node->right, temp->employeeNumber);
        }
        return node;
    }

    // Find the minimum value node
    EmployeeNode* findMin(EmployeeNode* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // In-order traversal
    void inOrder(EmployeeNode* node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << "Employee Number: " << node->employeeNumber 
             << ", Name: " << node->name 
             << ", Salary: " << node->salary << endl;
        inOrder(node->right);
    }

    // Pre-order traversal
    void preOrder(EmployeeNode* node) {
        if (node == NULL) return;
        cout << "Employee Number: " << node->employeeNumber 
             << ", Name: " << node->name 
             << ", Salary: " << node->salary << endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    // Post-order traversal
    void postOrder(EmployeeNode* node) {
        if (node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << "Employee Number: " << node->employeeNumber 
             << ", Name: " << node->name 
             << ", Salary: " << node->salary << endl;
    }
};

int main() {
    EmployeeBST bst;

    // Inserting employees
    bst.root = bst.insert(bst.root, 101, "Alice", 60000);
    bst.root = bst.insert(bst.root, 102, "Bob", 55000);
    bst.root = bst.insert(bst.root, 103, "Charlie", 70000);
    bst.root = bst.insert(bst.root, 104, "Diana", 50000);
    bst.root = bst.insert(bst.root, 105, "Edward", 65000);

    // Display the tree in-order
    cout << "In-order Traversal:" << endl;
    bst.inOrder(bst.root);
    
    // Pre-order traversal
    cout << "\nPre-order Traversal:" << endl;
    bst.preOrder(bst.root);

    // Post-order traversal
    cout << "\nPost-order Traversal:" << endl;
    bst.postOrder(bst.root);

    cout<<endl;
    cout<<endl;
    
    int empNumberToSearch;
    cout<<"Enter employee number to search: ";
    cin>>empNumberToSearch;
    EmployeeNode* found = bst.search(bst.root, empNumberToSearch);
    if (found != NULL)
        cout << "\nEmployee found: " << found->name << ", Salary: " << found->salary << endl;
    else
        cout << "\nEmployee not found" << endl;

    // Delete an employee
    cout<<endl;
    cout<<endl;
    int empNumberToDelete;
    cout<<"Enter employee number to delete: ";
    cin>>empNumberToDelete;
    bst.root = bst.deleteNode(bst.root, empNumberToDelete);

    // Display the tree after deletion
    cout << "\nAfter deleting employee "<<empNumberToDelete<<" :"<< endl;
    cout<<"================================================================"<<endl;
    cout << "In-order Traversal:" << endl;
    bst.inOrder(bst.root);

    // Pre-order traversal
    cout << "\nPre-order Traversal:" << endl;
    bst.preOrder(bst.root);

    // Post-order traversal
    cout << "\nPost-order Traversal:" << endl;
    bst.postOrder(bst.root);

    return 0;
}
