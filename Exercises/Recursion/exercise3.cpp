#include <iostream>

using namespace std;

int getB(int i){
    if(i == 1){
        return 1;
    } else if(i == 2){
        return 3;
    }

    return getB(i - 1) * 2;
}

int main(){
    for(int i = 1; i <= 8; i++){
        cout << "\'Planet\' " << i << " is " << double(4 + getB(i)) / 10 << " astronomical units from the sun according to the Titius-Bode law" << endl;
    }

    return 0;
}