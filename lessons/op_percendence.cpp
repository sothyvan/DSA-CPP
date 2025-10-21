#include <iostream>
#include <string>

using namespace std;

bool True(string id){
    cout << "True" << id << endl;
    return true;
}

bool False(string id){
    cout << "False" << id << endl;
    return false;
}

int main(){
    //

    bool result;

    // result = False("A") || False("B") && False("C"); 
    // && has a higher percedence than ||
    // So, the equation should be "False("A") || (False("B") && False("C"))"

    result = True("A") || False("B") && False("C");
    // Even though && has higher precedence, the short-circuit behavior of || means that once True("A") returns true, the entire right side (including the && expression) is skipped entirely.
    // Therefore, False("B") and False("C") are never called in this case!
    // So, the correct equation should be "True("A") || (False("B") && False("C"))"

    // Always use brackets around higher precedence statements

    cout << result;

    return 0;
}