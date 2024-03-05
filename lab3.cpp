#include <bits/stdc++.h>
using namespace std;
bool isvalid(string s) {
    if (s.empty()) {
        cout << "You didn't give any identifier name" << endl;
        return false;
    }
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'))
    {
        cout << "The first character is wrong!!! It must be a letter or underscore" << endl;
        return false;
    }
    for (int i = 1; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')) {
            cout << "Invalid character in identifier: '" << c <<"' please change it!!!"<< endl;
            return false;
        }
    }
    return true;
}
int main() {

    ifstream file("built in_identifier.txt");
   string input;
    cout << "Enter the identifier which you want to search for: ";
    cin >> input;

    string s;
    bool found = false;

    if (!isvalid(input)) {
        return 1;
    }

    while (file >> s) {
        if (s == input) {
            cout << "Identifier '" << input << "' is a built in identifier!!!!!!" << endl;
            found = true;
            break;
        }
}
    if (!found) {
        cout << "Identifier '" << input << "' is correct identifier!!!" << endl;
    }
 file.close();
return 0;
}
