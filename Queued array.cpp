#include<iostream>
using namespace std;
class queue{
	public:
	int num[10];
	int front;
	int rear;
	queue(){
		front=0;
		rear=0;
	}
	void enqueue(int value){
		if(isempty){
		num[rear]=value;
		rear++;
	    }
	}
	void dequeue(){
		front++;
	}
	void display(){
		cout<<"Queue elements:"<<endl;
		for(int i=front; i<rear; i++){
			cout<<num[i]<<endl;
		}
	}
	bool isempty(){
		if(front==rear){
			return true;
		}
		else{
			return false;
		}
	}
	bool isfull(){
		if(rear==10){
			return true;
		}
		else{
			return false;
		}
	}
};
int main(){
	queue q1;
	q1.enqueue(30);
	q1.display();
	q1.dequeue();
	q1.enqueue(50);
	q1.display();
	q1.enqueue(60);
	q1.enqueue(70);
	q1.enqueue(80);
	q1.display();
	q1.dequeue();
	q1.display();	
}
