#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
class QueueLL {
private:
	node* rear=NULL;
	node* front=NULL;
public:
	bool isEmpty() {
		if(front==NULL) {
			return 1;
		}
		return 0;
	}

	void Enqueue(int x) {
		node* newnode= new node;
		newnode->data=x;
		newnode->next=NULL;

		if(isEmpty()) {
			front=newnode;
			rear=newnode;
			cout<<"Added: "<<newnode->data<<endl;
			return;
		}
		rear->next=newnode;
		cout<<"Added: "<<newnode->data;
		rear=rear->next;
	}

	void Dequeue() {
		if(isEmpty()) {
			cout<<"Underflow!\n";
			return;
		}
		node* del= front;
		front=front->next;
		cout<<"Deleted: "<<del->data<<endl;
		delete del;
		// if the queue had one element
		if(isEmpty()) {
			rear=NULL;
		}
	}

	void Display() {
		if(isEmpty()) {
			cout<<"Empty queue!\n";
			return;
		}
		node* temp= front;
		while(temp!=NULL) {
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}


	~QueueLL() {
		while (front != NULL) {
			node* del = front;
			front = front->next;
			delete del;
		}

		rear = NULL;
	}


















};

int main() {
    QueueLL q;
    int choice, x;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            q.Enqueue(x);
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            q.Display();
            cout << endl;
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
