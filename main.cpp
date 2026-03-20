#include <iostream>

using namespace std;

void printOptions() {
    cout << "[1] Enter Expense" << endl;
    cout << "[2] Adjust Budget" << endl;
    cout << "[3] Print Budget" << endl;
    cout << "[4] Quit" << endl;
}

double calcSpending(double expense, double totalSpent) {
    totalSpent = totalSpent + expense;
    return totalSpent;
}

void printBudget(double spending, double budget) {
    int percentSpent = (spending / budget) * 100;
    
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 20; i++) {
        if (i < (percentSpent/5) ) {
            cout << "|";
        }
        else {
            cout << "-";
        }
    }
    cout << " %" << percentSpent << " of the budget spent";
    cout << endl;
    cout << "---------------------------------------" << endl;

    cout << "Your budget this month is $" << budget << endl;
    cout << "You have spent $" << spending << " this month" << endl;
}

int main() {
    double monthlyBudget = 0;
    double currentSpending = 0;
    double expense = 0;

    while(true) {
        int menuOption;
        printOptions();

        cout << "Option: ";
        cin >> menuOption;

        if (menuOption == 1) {
            cout << "What is the expense? ";
            cin >> expense;
            if (monthlyBudget < 1) {
                cout << "There is an invalid budget. Enter a new Budget." << endl;
                expense = 0;
            }
            currentSpending = calcSpending(expense, currentSpending);
        }
        else if (menuOption == 2) {
            cout << "What is the new budget? ";
            continue;
        }
        else if (menuOption == 3) {
            printBudget(currentSpending, monthlyBudget);
        }
        else if (menuOption == 4) {
            return false;
        }
        else {
            cout << "Invalid Choice. Try Again: ";
            cin >> menuOption;
        }
    }
    return 0;
}