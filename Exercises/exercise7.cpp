#include <iostream>

using namespace std;

int getSumDigits(int n){
    if(n == 0){
        return n;
    }

    return n % 10 + getSumDigits(n / 10);
}

int main(){
    int n;
    cout << "\nEnter an integer: ";
    cin >> n;
    cout << "The sum of the digits of this number is: " << getSumDigits(n) << endl;

    return 0;
}