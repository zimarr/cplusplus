#include <iostream>
#include <string>

using namespace std;

int main(){
    string in;

    cout << "\nEnter a string: ";
    cin >> in;

    bool isPalindrome = true;

    for(int i = 0; i < in.size() / 2; i++){
        if(in[i] != in[in.size() - i - 1]){
            isPalindrome = false;
        }
    }

    if(isPalindrome){
        cout << "\nThat IS a palindrome...\n";
    } else {
        cout << "\nThat is NOT a palindrome...\n";
    }


    return 0;
}