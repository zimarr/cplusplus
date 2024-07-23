#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cout << "\nInput a string: ";
    cin >> input;

    //string output(input.size(), " ");

    string output = "";

    for(int i = 0; i < input.size(); i++){
        output += input[input.size() - i - 1];
    }

    cout << "That string reversed is: " << output << endl;


    return 0;
}