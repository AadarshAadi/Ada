#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

class stack
{
private:
    Node* top;

public:

stack(){
    top = nullptr;

}

void push(int item){
    Node* newnode = new Node();
    newnode->data = item;
    newnode->link = top;
    top = newnode;
    cout << item << " pushed onto stack\n";
}

void pop(){
    if(top == nullptr){
        cout << "Stack is empty\n";
            return;
    }
    Node* temp = top;
    top = top->link;
    cout << temp->data << " popped from stack\n";
    delete temp;
}

int peek(){
    if(top != nullptr){
        return top->data;
    } else {
         cout << "Stack is empty\n";
         return 0;
    }
}
};

int main() {
    stack Stack;
    int choice, item;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> item;
                Stack.push(item);
                break;
            case 2:
                Stack.pop();
                break;
            case 3:
                cout << "Top element is " << Stack.peek() << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}