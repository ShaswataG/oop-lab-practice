using namespace std;
#include<iostream>

class Student {
public:
    string name;
    int roll;

    void setName(string name = "") {
        this->name = name;
    }
    void setRoll(int roll = 0) {
        this->roll = roll;
    }
    string getName() {
        return this->name;
    }
    int getRoll() {
        return this->roll;
    }
};

class View {
public:
    void printDetails(string name, int roll) {
        cout << "Student name : " << name << endl;
        cout << "Student roll no.: " << roll << endl;
    }
};

class Controller {
public:
    Student model;
    View view; 
    void setName(string name) {
        model.setName(name);
    }
    void setRoll(int roll) {
        model.setRoll(roll);
    }
    string getName() {
        return model.getName();
    }
    int getRoll() {
        return model.getRoll();
    }
    void updateView() {
        view.printDetails(model.getName(), model.getRoll());
    }
};

int main() {
    while (1) {
        cout << "Press 1 to "
    }
    return 0;
}