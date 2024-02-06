#include <iostream>

using namespace std;

bool isNumericConstant(const string& input) {
    for (char ch : input) {
        // Check if the character is not a digit
        if (ch < '0' || ch > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string user_input;
    cout << "Enter a value: ";
    cin >> user_input;

    if (isNumericConstant(user_input)) {
        cout << "Numeric constant" << endl;
    } else {
        cout << "Not numeric" << endl;
    }

    return 0;
}
