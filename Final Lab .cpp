#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool isKeyword(const string& token) {
    vector<string> keywords = {"int", "float", "double", "char", "long", "short",
                               "bool", "void", "auto", "const", "static", "unsigned",
                               "signed", "volatile", "wchar_t", "char16_t", "char32_t",
                               "if", "else if", "else","while", "do-while","switch", "case","default", "Break","parameters",
                               "return_type","function_name", "Continue statements","arr", "array","*ptr", "Pointer","Class",
                               "ClassName ","Object", "obj","inheritance", "polymorphism","class DerivedClass", "accessSpecifier","BaseClass",
                               "virtual","function", "function overriding","File I/O", "ifstream","ofstream", "Exception Handling","try", "catch","throw", "finally",
                               "namespaces", "std","include", "unordered","false", "true","string","cout", "cin","for","while", "do-while","switch","case",
                               "choice","encapsulation","constructors", "public","private","get", "set","main","return", "structures","struct","loop"};
                               for (const string& keyword : keywords) {
        if (token == keyword)
            return true;
    }
    return false;
}

bool isIdentifier(const string& token) {
    if (!isalpha(token[0]) && token[0] != '_')
        return false;
    for (char c : token) {
        if (!isalnum(c) && c != '_')
            return false;
    }
    return true;
}

bool isNumericConstant(const string& token) {
    for (char c : token) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isCharConstant(const string& token) {
    return token.length() == 3 && token[0] == '\'' && token[2] == '\'';
}

bool isStringConstant(const string& token) {
    return token.length() >= 2 && token.front() == '"' && token.back() == '"';
}

bool isOperator(char c) {
    string operators = "+-*/%<>=!&|^";
    return operators.find(c) != string::npos;
}

bool isArithmeticOperator(const string& token) {
    string arithmeticOperators = "+-*/%";
    return token.length() == 1 && arithmeticOperators.find(token) != string::npos;
}

bool isRelationalOperator(const string& token) {
    string relationalOperators = "<>==<=>=";
    return relationalOperators.find(token) != string::npos;
}

bool isLogicalOperator(const string& token) {
    return token == "&&" || token == "||" || token == "!";
}

bool isAssignmentOperator(const string& token) {
    return token == "=" || token == "+=" || token == "-=" || token == "*=" || token == "/=" || token == "%=" || token == "==";
}

bool isIncrementDecrementOperator(const string& token) {
    return token == "++" || token == "--";
}

bool isPunctuator(char c) {
    string punctuators = "{}[](),;:";
    return punctuators.find(c) != string::npos;
}

bool isComment(const string& token) {
    return token.length() >= 2 && token.substr(0, 2) == "//";
}

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    string token;
    bool inToken = false;
    for (char c : input) {
        if (isspace(c) || isPunctuator(c) || isOperator(c)) {
            if (inToken) {
                tokens.push_back(token);
                token.clear();
                inToken = false;
            }
            if (!isspace(c))
                tokens.push_back(string(1, c));
        } else {
            token += c;
            inToken = true;
        }
    }
    if (!token.empty())
        tokens.push_back(token);
    return tokens;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return 1;
    }
    string line;
    vector<string> tokens;
    while (getline(file, line)) {
        vector<string> lineTokens = tokenize(line);
        tokens.insert(tokens.end(), lineTokens.begin(), lineTokens.end());
    }
    file.close();
    cout  << "-----------------COMPILER DESIGN [H]-------------- " << endl;
    cout  << "---------Supervised By:NAZMUS SAKIB SHAN---------- " << endl;
    cout  << "------------------MD. ASIF KARIM------------------ " << endl;
    cout  << "--------------------21-44751-1---------------------" << endl;
    cout  << "--Scan Lexical Element  of The Source File Report--" << endl;
    cout  << " **************************************************" << endl;
    cout  << " **************************************************" << endl;
    cout  << "                                                    " << endl;
    cout  << "                                                    " << endl;
    for (const string& token : tokens) {
        if (isKeyword(token)) {
            cout << token << " is a keyword." << endl;

        } else if (isIdentifier(token)) {
            cout << token << " is an identifier." << endl;

        } else if (isNumericConstant(token)) {
            cout << token << " is a numeric constant." << endl;

        } else if (isCharConstant(token)) {
            cout << token << " is a character constant." << endl;

        } else if (isStringConstant(token)) {
            cout << token << " is a string constant." << endl;

        } else if (isArithmeticOperator(token)) {
            cout << token << " is an arithmetic operator." << endl;

        } else if (isRelationalOperator(token)) {
            cout << token << " is a relational operator." << endl;

        } else if (isLogicalOperator(token)) {
            cout << token << " is a logical operator." << endl;

        } else if (isAssignmentOperator(token)) {
            cout << token << " is an assignment operator." << endl;

        } else if (isIncrementDecrementOperator(token)) {
            cout << token << " is an increment/decrement operator." << endl;

        } else if (isPunctuator(token[0])) {
            cout << token << " is a punctuator." << endl;

        } else if (isComment(token)) {
            cout << token << " is a comment." << endl;

        } else {
            cout << token << " is an invalid token." << endl;


        }

    cout<< "***************************************************" << endl;
    }
    cout  << "****************THE END****************************" << endl;
    cout  << "***************************************************" << endl;
    return 0;
}
