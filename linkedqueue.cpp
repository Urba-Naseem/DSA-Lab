#include<iostream>
using namespace std;
class queue{
	public:
	int num;
    queue *next;
    
    queue(){
    	num=0;
    	next=NULL;
	}
};
class linkedqueue{
	public:
   
	queue *front;
	queue *rear;
	
	
	linkedqueue(){
		front=NULL;
		rear=NULL;
	}
	bool isempty(){
		if (front==NULL && rear==NULL){
			return true;
		}
		else{
			return false;
		}
	} 
	void enqueue(int value){
		queue *newnode =new queue;
		newnode->num=value;
		newnode->next=NULL;
		if(isempty()){
			front=rear=newnode;
			return;
    		}
    		rear->next=newnode;
    		rear=newnode;
	}
	void dequeue(){
		queue *temp=front;
		if(isempty()){
			cout<<"Queue is empty.."<<endl;
			
		}
		else{
			front=front->next;
			delete temp;
		}
	}
	void display(){
		queue *d =front;
		cout<<"Queue Elements: "<<endl;
		while(d!=NULL){
			cout<<d->num<<endl;
			d=d->next;
			}
	}
		
};
int main(){
	linkedqueue l;
	l.enqueue(101);
	l.enqueue(981);
	l.enqueue(620);
	l.enqueue(931);
	l.display();
	l.dequeue();
	l.dequeue();
	l.display();
	
	
}
