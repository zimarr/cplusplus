/*
Swaps two integers inputted by the user
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int a, b;

    cout << "\nInput first number: ";
    cin >> a;

    cout << "Input second number: ";
    cin >> b;

    swap(a, b);

    cout << "\nThe first number is now " << a << endl;
    cout << "The second number is now " << b << endl;
}
