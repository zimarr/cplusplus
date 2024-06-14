/*
Calculates the volume of a sphere with radius inputted by user.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int r;

    cout << "\nInput the radius of the sphere: ";
    cin >> r;

    cout << "\nThe volume of this sphere is " << 4.0 * pow(r, 3) * M_PI / 3 << " cubic units" << endl;
}