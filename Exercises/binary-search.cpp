#include <iostream>

using namespace std;

int helper(int a[10], int b, int high, int mid, int low){
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

int binarySearch(int a[10], int b){
    return helper(a, b, 9, 4, 0);
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b;

    cout << "What number are you looking for? ";
    cin >> b;
    cout << "This number is at index " << binarySearch(arr, b) << " of this array!";

    return 0;
}