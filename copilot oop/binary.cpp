#include<iostream>
#include<stack>

using namespace std;


//made a menu to convert from decimal to binary
int main()
{
    int choice;
    int num;
    int rem;
    stack<int> s;
    cout << "Enter a number: ";
    cin >> num;
    cout << "1. Decimal to binary" << endl;
    cout << "2. Decimal to octal" << endl;
    cout << "3. Decimal to hexadecimal" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            while(num != 0)
            {
                rem = num % 2;
                s.push(rem);
                num = num / 2;
            }
            cout << "Binary number is: ";
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << endl;
            break;
        case 2:
            while(num != 0)
            {
                rem = num % 8;
                s.push(rem);
                num = num / 8;
            }
            cout << "Octal number is: ";
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << endl;
            break;
        case 3:
            while(num != 0)
            {
                rem = num % 16;
                s.push(rem);
                num = num / 16;
            }
            cout << "Hexadecimal number is: ";
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    return 0;
}