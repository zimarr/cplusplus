#include <iostream>

using namespace std;

int getNum(int h){
    if (h == 1) {
        return 1;
    }

    return h * h + getNum(h - 1);
}

int main(){
    int h;

    cout << "\nEnter the height of the pyramid: ";
    cin >> h;
    cout << "There are a total of " << getNum(h) << " spherical objects in this pyramid" << endl;


    return 0;
}