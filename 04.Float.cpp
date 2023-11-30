using namespace std;
#include<iostream>

class Float {
public:
    float a;
    float operator * (Float b) {
        return a+b.a;
    }
    float operator / (Float b) {
        return a/b.a;
    }
    float operator + (Float b) {
        return a+b.a;
    }
    float operator - (Float b) {
        return a-b.a;
    }
    // float operator % (Float b) {     // error
    //     return a%b.a;
    // }
};

int main() {
    Float a, b;
    cout << "Enter first float : ";
    cin >> a.a;
    cout << "Enter second float : ";
    cin >> b.a;
    cout << "a+b = " << a+b << endl;
    cout << "a-b = " << a-b << endl;
    cout << "a/b = " << a/b << endl;
    cout << "a*b = " << a*b << endl; 
    return 0;
}