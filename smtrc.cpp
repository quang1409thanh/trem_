#include <iostream>
using namespace std;
bool x(){
    return true;
}

void ut1() {
    if(x() == 0) {
        cout << "x is equal to FLOWS" << endl;
    } else if(x() == 1) {
        cout << "x is equal to FLOWS+1" << endl;
    } else if(x() == -1) {
        cout << "x is equal to -FLOWS" << endl;
    } else {
        cout << "x is not equal to FLOWS" << endl;
    }
}