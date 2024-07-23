#include <iostream>

using namespace std;

int getSumDigits(int n){
    if(n == 0){
        return 0;
    }

    return n % 10 + getSumDigits(n / 10);
}

int getDigitalRoot(int n){
    if(n / 100 == 0){
        return getSumDigits(n);
    }

    return getDigitalRoot(getSumDigits(n));
}

int main(){
    int n;
    cout << "\nEnter an integer: ";
    cin >> n;
    cout << "The digital root of this number is: " << getDigitalRoot(n) << endl;

    return 0;
}