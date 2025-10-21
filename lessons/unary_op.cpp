#include <iostream>

using namespace std;

int main(){

    // bool b = true;
    // !b;
    // // !b this exprression doesn't assign b to false
    // // the coreect approach is b = !b;
    // cout << b; // result is 1

    int arr[4] = {1,2,3,4};
    
    int *ptr1 = arr;
    int *ptr2 = ptr1++;
    cout << *ptr1 << endl; //result 2
    cout << *ptr2 << endl; //result 1
    return 0;
}