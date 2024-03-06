#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    char op;
    float num1,num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op){
        case '+':
            cout << "Result: " << num1 + num2;
            break;
        case '-':
            cout << "Result: " << num1 - num2;
            break;
        case '*':
            cout << "Result: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2;
            else
                cout << "Error: Division by zero";
            break;
        default:
            cout << "Error! Operator is not correct";
    }
    return 0;
}