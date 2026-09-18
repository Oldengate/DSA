#include <iostream>
using namespace std;

// Linear Queue using dynamic array
class Queue {
private:
    int rear = -1;
    int front = -1;
    int *arr;
    int capacity;

public:

    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
    }

    bool isEmpty() {
        if (front == -1 || front > rear) {
            return 1;
        }
        return 0;
    }

    bool isFull() {
        if (rear == capacity - 1) {
            return 1;
        }
        return 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty()) {
            rear += 1;
            front += 1;
            arr[rear] = x;
            cout << "Added " << x << endl;
            return;
        }

        rear += 1;
        arr[rear] = x;
        cout << "Added " << x << endl;
    }

    void dequeue() {
        // checking for no element
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        int x = arr[front];
        cout << "Removed " << x << endl;
        front++;

        // if the queue now becomes empty
        if (isEmpty()) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "empty queue\n";
            return;
        }

        int temp = front;

        while (temp <= rear) {
            cout << arr[temp] << " ";
            temp++;
        }

        cout << endl;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};


int main() {
    int size;

    cout << "Enter queue capacity: ";
    cin >> size;

    Queue q(size);

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display queue
    cout << "Queue: ";
    q.display();

    // Dequeue one element
    q.dequeue();

    // Display after dequeue
    cout << "Queue after dequeue: ";
    q.display();

    // Remove remaining elements
    q.dequeue();
    q.dequeue();

    // Try displaying empty queue
    cout << "Queue after removing all elements: ";
    q.display();

    return 0;
}
