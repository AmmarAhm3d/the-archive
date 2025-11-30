#include <iostream>
using namespace std;

void print01(int k, string answer="") {
    if (k == 0) 
        cout << answer << endl;
    
    // append 0s and 1s to answer string recursively
    else {
        print01(k - 1, answer + "0");
        print01(k - 1, answer + "1");
    }
}

void main() {
    print01(2);
    
}