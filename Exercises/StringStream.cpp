#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> result;
    int i = 0;
    while (str.length() > 0 && i < str.length()) {
        if (str[i] == ',') {
            result.push_back(stoi(str.substr(0, i)));
            str = str.substr(i + 1);
            i = 0;
        } else {
            i++;
        }
    }
    result.push_back(stoi(str));
    
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
