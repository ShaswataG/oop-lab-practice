using namespace std;
#include<iostream>

class shape {
public:
    double base, height;
    shape(int a = 0, int b = 0) {
        base = a;
        height = b;
    }
    void getData() {
        double a, b;
        cout << "Enter Base : ";
        cin >> a;
        cout << "Enter Height : ";
        cin >> b;
        base = a, height = b;
    }
    virtual void displayArea() {
        cout << "Shape undefined" << endl;
    }
};

class triangle : public shape {
public:
    void displayArea() {
        double area = 0.5*base*height;
        cout << "Area of the triangle : " << area << endl;
    }
};

class rectangle : public shape {
public:
    void displayArea() {
        double area = base*height;
        cout << "Area of the rectangle : " << area << endl;
    }
};

int main() {
    int choice;
    shape *ptrA, * ptrB;
    triangle t;
    rectangle r;
    ptrA = &t;
    ptrB = &r;
    while (1) {
        cout << "Press 1 to enter dimensions of triangle.\nPress 2 to enter dimensions of rectangle.\nPress 3 to get area of triangle.\nPress 4 to get area of rectangle.\nPress 5 to exit.\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                t.getData();
                break;
            case 2:
                r.getData();
                break;
            case 3:
                t.displayArea();
                break;
            case 4:
                r.displayArea();
                break;
            default:
                exit(0);
                break;
        }
    }
    return 0;
}