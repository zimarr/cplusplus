#include <iostream>

using namespace std;

int getGCD(int x, int y){
    if((x % y) % 2 == 0){
        return y;
    }

    return(x, x % y);
}

int main(){
    int x, y;

    cout << "\nEnter two integers separated by a space: ";
    cin >> x >> y;
    cout << "The greatest common divisor of these integers is " << getGCD(x, y) << "!" << endl;

    return 0;
}