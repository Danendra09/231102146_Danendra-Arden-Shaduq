#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    // It allows user to enter the operands
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enters +
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    // If user enters -
    case '-':
        cout << "Result: " << num1 - num2;
        break;
    // If user enters *
    case '*':
        cout << "Result: " << num1 * num2;
        break;
    // If user enters /
    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! Operator is not correct";
    } // switch statement ends
    return 0;
}