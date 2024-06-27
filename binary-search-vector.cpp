#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> a, int b, int high, int mid, int low){
    if(low > high){
        cout << high << " " << low << endl;
        return -1;
    }

    if(b > a[mid]){
        return helper(a, b, high, (high - mid - 1) / 2 + mid + 1, mid + 1);
    } else if (b < a[mid]) {
        return helper(a, b, mid - 1, (mid - 1 - low) / 2 + low, low);
    } else {
        return mid;
    }
}

int binarySearch(vector<int> a, int b){
    int len = a.size();
    return helper(a, b, len - 1, (len - 1) / 2, 0);
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b;

    cout << "What number are you looking for? ";
    cin >> b;
    cout << "This number is at index " << binarySearch(vec, b) << " of this vector!";

    return 0;
}