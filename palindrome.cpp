#include <iostream>

using namespace std;

bool isPalindrome(string s){
    if(s.length() <= 2){
        return s[0] == s[s.length() - 1];
    }
    
    if(isPalindrome(s.substr(1, s.length() - 2))){
        return s[0] == s[s.length() - 1];
    } else {
        return false;
    }
}


int main(){
    string str;
    cin >> str;

    cout << isPalindrome(str);

    return 0;
}