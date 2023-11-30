using namespace std;
#include<iostream>

class Bank {
public:
    int accNo;
    string accHolder;
    double balance;
public:
    Bank(string name = "no name", int no = 0, double amt = 0) {
        accHolder = name;
        accNo = no;
        balance = amt;
    }
    void create(int);
    void deposit();
    void withdraw();
    void display();
};

void Bank::create(int a) {
    accNo = a;
    cout << "   Enter account holder name : ";
    cin >> accHolder;
    cout << "   Congratulations " << accHolder << "!" << endl;
    cout << "   Your account has been successfully created!" << endl;
    cout << "   Your account number is " << accNo << "." << endl;
    cout << "   Kindly remember it for future reference.\n";
}

void Bank::deposit() {
    cout << "   Enter amount to be deposited : ";
    double amt;
    cin >> amt;
    balance+= amt;
    cout << "   Rs. " << amt << " has been deposited on account number " << accNo << ".\nThank you.\n"; 
}

void Bank::withdraw() {
    cout << "   Enter amount to be withdrawn : ";
    double amt;
    cin >> amt;
    balance-= amt;
    cout << "   Rs. " << amt << " has been withdrawn from account number " << accNo << ".\nThank you.\n";
}

void Bank::display() {
    cout << "   Account holder name : " << accHolder << endl;
    cout << "   Account number : " << accNo << endl;
    cout << "   Account balance : " << balance << endl;
}

int main() {
    int choice, n, i, x;
    i = 0;
    cout << "Maximum number of accounts : ";
    cin >> n;
    Bank b[n];
    while (1) {
        cout << "\n\nMENU\nPress 1 to create account.\nPress 2 to deposit.\nPress 3 to withdraw.\nPress 4 to display account details.\nPress 5 to exit.\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                b[i].create(i+1);
                i++;
                break;
            case 2:
                cout << "   Enter account number : ";
                cin >> x;
                if (b[x-1].accNo == 0) {
                    cout << "   Account doesn't exist.\n";
                    break;
                }
                b[x-1].deposit();
                break;
            case 3:
                cout << "E  nter account number : ";
                cin >> x;
                if (b[x-1].accNo == 0) {
                    cout << "   Account doesn't exist.\n";
                    break;
                }
                b[x-1].withdraw();
                break;
            case 4:
                cout << "   Enter account number : ";
                cin >> x;
                if (b[x-1].accNo == 0) {
                    cout << "   Account doesn't exist.\n";
                    break;
                }
                b[x-1].display();
                break;
            default:
                exit(0);
                break;
        }

    }
    return 0;
}