#include <iostream>

using namespace std;

int fib(int a){
    if(a == 1 || a == 2){
        return 1;
    } else if (a == 0) {
        return 0;
    }
    
    return fib(a - 1) + fib(a - 2);
}

int main(){
    int limit;

    cout << "\nEnter number of steps: ";
    cin >> limit;
    cout << "The Fibonacci sequence produces the value " << fib(limit) << " at step " << limit << endl;

    return 0;
}