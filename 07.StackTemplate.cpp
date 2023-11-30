using namespace std;
#include<iostream>

template<class T>
class Stack {
    int size, top;
    int* s;
public:
    void initStack();
    void push(int);
    T pop();
    int isEmpty();
    int isFull();
    T topElement();
};

template<class T>
void Stack<T>::initStack() {
    cout << "Enter size of stack : ";
    cin >> size;
    s = new T[size];
    top = -1;
}

template<class T>
void Stack<T>::push(int x) {
    if (top == size-1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    top++;
    s[top] = x;
}

template<class T>
T Stack<T>::pop() {
    if (top == -1) {
        return -1;
    }
    int x = s[top];
    top--;
    return x;
}

template<class T>
int Stack<T>::isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

template<class T>
int Stack<T>::isFull() {
    if (top == size-1) return 1;
    else return 0;
}

template<class T>
T Stack<T>::topElement() {
    if (top == -1) return -1;
    else return s[top];
}

int main() {
    int choice, x;
    Stack<int> s;
    while (1) {
        cout << "Press 1 to create a stack.\nPress 2 to push.\nPress 3 to pop.\nPress 4 to check if stack is empty.\nPress 5 to check if stack is full.\nPress 6 to view top element.\nPress 7 to exit.\n";
        cin >> choice;
        switch(choice) {
            case 1:
                s.initStack();
                break;
            case 2:
                cout << "Enter value to be pushed : ";
                cin >> x;
                s.push(x);
                break;
            case 3:
                x = s.pop();
                if (x == -1) {
                    cout << "Stack underflow!" << endl;
                } else {
                    cout << x << " is popped" << endl;
                }
                break;
            case 4:
                x = s.isEmpty();
                if (x == 1) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                x = s.isFull();
                if (x == 1) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 6:
                x = s.topElement();
                if (x == -1) {
                    cout << "Stack underflow." << endl;
                } else {
                    cout << "Element at top is : " << x << endl;
                }
                break;
            default:
                exit(0);
        }
    }
    return 0;
}