#include <iostream>

using namespace std;

int raiseToPower(int n, int k) {
    if(k == 0){
        return 1;
    }

    return n * raiseToPower(n, k - 1);
}

int main(){
    int n;
    int k;

    cout << "\nEnter a number and its power separated by a space (n k): ";
    cin >> n >> k;
    cout << n << " to the power of " << k << " is " << raiseToPower(n, k) << endl;

    return 0;
}