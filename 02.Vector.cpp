using namespace std;
#include<iostream>
#include<vector>

class Vector {    
    vector<int> v;
public:
    void create();
    void modify();
    void multiply();
    void display();
};

void Vector::create() {
    int n, x;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void Vector::modify() {
    int choice, x, i;
    cout << "Press 1 to push new elements.\nPress 2 to replace an element.\nPress 3 to delete an element.\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter element to be pushed : ";
        cin >> x;
        v.push_back(x);
        break;
    case 2:
        cout << "Enter index where you want to replace an element : ";
        cin >> i;
        if ((i < 0) || (i >= v.size()-1)) {
            cout << "Index doesn't exist." << endl;
            break;
        }
        cout << "Enter the element : ";
        cin >> x;
        v[i] = x;
        break;
    case 3:
        cout << "Enter index you want to delete element : ";
        cin >> i;
        if ((i < 0) || (i >= v.size()-1)) {
            cout << "Index doesn't exist." << endl;
            break;
        }
        x = v[i];
        v[i] = 0;
        cout << "Element deleted is : " << x << endl;
        break;
    default:
        exit(0);
        break;
    }
}

void Vector::multiply() {
    cout << "Enter scalar value to be multiplied : ";
    int x;
    cin >> x;
    for (int i = 0; i < v.size(); i++) {
        v[i] *= x;
    }
}

void Vector::display() {
    cout << "Elements are : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector v;
    int choice;
    while (1) {
        cout << "Press 1 to create a vector.\nPress 2 to modify the vector.\nPress 3 to multiply the vector by a scalar.\nPress 4 to display the vector.\nPress 5 to exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            v.create();
            break;
        case 2:
            v.modify();
            break;
        case 3:
            v.multiply();
            break;
        case 4:
            v.display();
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}