/*
Evaluates the sum of 2 integers inputted by the user.
*/
#include <iostream>
using namespace std;

int sum2(int a, int b){

    return a + b;
}


int main(){
    int a, b;

    cout << "\nInput first number: ";
    cin >> a;

    cout << "Input second number: ";
    cin >> b;

    cout << "\nThe sum of the two numbers is " << a + b << endl;
}
