using namespace std;
#include<iostream>
#include<cmath>

class Bank {
public:
    string accHolder;
    int accNo;
    double balance;
    Bank(string a = "", int b = 0) {
        accHolder = a;
        accNo = b+1;
    }
    void withdraw(double amt = 0) {
        balance-= amt;
        cout << "Withdrawn Rs. " << amt << " from account number " << accNo << ".\n";
    }
    void deposit(double amt = 0) {
        balance+= amt;
        cout << "Withdrawn Rs. " << amt << " from account number  " << accNo << ".\n";
    }
    void display() {
        cout << "Account holder name : " << accHolder << endl;
        cout << "Account number : " << accNo << endl;
        cout << "Account balance : " << balance << endl;
    }
};

class SavAcct : public Bank {
public:
    const int rateOfInterest = 5;
    SavAcct(string a = "", int b = 0):Bank(a, b) {
    }
    void compoundInterest(int years = 0) {
        int factor = pow(1+(rateOfInterest/100), years);
        balance *= factor;
    }
};

class CurrAcct : public Bank {
private:
    const double minBal = 100;
public:
    CurrAcct(string a = "", int b = 0):Bank(a, b) {
    }
    void chequeBook(int n, double amt) {
        char c;
        if (n == 1) {
            deposit(amt);
        } else if (n == 2) {
            if (checkBalanceAfterWithdraw(amt, minBal) == 1) {
                withdraw(amt);
            } else if (checkBalanceAfterWithdraw(amt, minBal) == 0) {
                cout << "Withdrawing Rs. " << amt << " from you account will result in service charges as account balance will be below minimum balance i.e. " << minBal << ".\n";
                cout << "Do you wish to continue (y/n) : ";
                cin >> c;
                if (c == 'y' || c == 'Y') {
                    withdraw(amt);
                    imposePenalty();
                } else if (c == 'n' || c == 'N') {
                    cout << "No amount withdrawn as you chose to decline withdrawing.\n";
                    return;
                }
            } else if (checkBalanceAfterWithdraw(amt, minBal) == -1) {
                cout << "Sorry, you don't have the required amount in your account.\n";
            }
        }
    }
    void imposePenalty() {
        double charge = 50;
        balance-= charge;
    }
    int checkBalanceAfterWithdraw(double amt, double minBal) {
        if (balance-amt >= minBal) {
            return 1;
        } else if (balance-amt >= 0 && balance-amt < minBal) {
            return 0;
        } else if (balance-amt < 0) {
            return -1;
        }
    }
};

int main() {
    int choice, flag;
    string x, y;
    cout << "Press 1 to for savings account.\nPress 2 for current account.\n";
    cout << "Enter choice : ";
    cin >> choice;
    switch(choice) 
    {
    case 1:
        {
            flag = 0;
            int n;
            double amt;
            cout << "Enter account holder's name : ";
            cin >> x;
            SavAcct s(x, 1);
            break;
            while (1) {
                cout << "Press 1 to display account details.\nPress 2 for compound interest.\nPress 3 to withdraw.\nPress 4 to deposit.\n";
                cout << "Enter choice : ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        s.display();
                        break;
                    case 2:
                        cout << "Enter number of years : ";
                        cin >> n;
                        s.compoundInterest(n);
                        cout << "Available balance after compount interest for " << n << " years " << " at a rate of interest of " << s.rateOfInterest << " is Rs. " << s.balance << ".\n"; 
                        break;
                    case 3:
                        cout << "Enter amount to be withdrawn : ";
                        cin >> amt;
                        s.withdraw(amt);
                        break;
                    case 4:
                        cout << "Enter amount to be deposited : ";
                        cin >> amt;
                        s.deposit(amt);
                        break;
                    default:
                        exit(0);
                }
            }
            break;
        }
    case 2: 
        {
            flag = 1;
            cout << "Enter account holder's name : ";
            cin >> x;
            CurrAcct c(x, 1);
            while (1) {
                cout << "Press 1 to display account details.\nPress 2 to go to cheque book.\nPress 3 to withdraw.\nPress 4 to deposit.\n";
                cout << "Enter choice : ";
                cin >> choice;
                switch(choice) {
                    case 1:
                        c.display();
                        break;
                    case 2:
                        cout << "\nCheque Book\n    Press 1 to withdraw.\n  Press 2 to deposit.\n";
                        cout << "Enter choice : ";
                        cin >> choice;
                        if (choice == 1)
                        c.chequeBook(choice);
                }
            }
            break;
        }
    }
    return 0;
}