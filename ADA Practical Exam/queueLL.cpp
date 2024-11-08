#include<iostream>
using namespace std;

//struct Node
//{
//   int data;
//    Node* link;
//};

class Node {
public:
    int data;
    Node* link;

    Node(int data) {
        this->data = data;
        this->link = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:

Queue(){
    front = rear = nullptr;

}

void enqueue(int data){
    Node* newnode = new Node(data);
    if (rear == nullptr) {
        front = rear = newnode;
        return;
    }
    rear->link = newnode;
    rear = newnode;
}
   
int dequeue(){
    if(front == nullptr){
        cout << "Queue is empty\n";
            return 0;
    }
    Node* temp = front;
    int data = temp->data;
    front = front->link;

    if (front==nullptr){
    rear = nullptr;
    }
    delete temp;
    return data;
}

int peek(){
        if(front == nullptr){
        cout << "Queue is empty" << endl;
        return 0;

    } else {
         return front == nullptr;
    }
}
 bool isEmpty() {
        return front == nullptr;
    }
     ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
}
};


int main() {
    Queue q;
    int choice, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element is: " << q.peek() << endl;
                break;
            case 4:
            if (q.isEmpty()){
             cout << "Queue is empty." << endl;
            }else{
                    cout << "Queue is not empty." << endl;
            }
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}