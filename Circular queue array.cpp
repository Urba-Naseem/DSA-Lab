#include <iostream>
using namespace std;

const int queueCapacity = 100;

class queue {
public:
    int array[queueCapacity];
    int front;
    int rear;
    int count;

    queue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    void enqeue(int value) {
        if (count == queueCapacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        array[rear] = value;
        rear = (rear + 1) % queueCapacity;
        count++;
    }

    int deqeque() {
        if (count == 0) {
            cout << "Queue is empty!!" << endl;
            return -1; // Return an error value if the queue is empty
        }
        int value = array[front];
        front = (front + 1) % queueCapacity;
        count--;
        return value;
    }
    void display()
    {
    for(int i=0;i<count;i++)
    {
    int index =(front+i)%queueCapacity;
    cout<<array[index]<<endl;
	}
	}
};


int main() {
    queue q1;
    q1.enqeue(10);
    q1.enqeue(20);
    q1.enqeue(30);
q1.display();
    q1.deqeque() ;
	q1.deqeque();
q1.display();
}
