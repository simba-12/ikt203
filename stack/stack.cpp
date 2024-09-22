
#include <iostream>         // Iclude the standard strem libaray
#include <stack>            // Include stack data
#include <string>           // String libraray
#include <cmath>            // include matematical library  such as sin and cos
#include <unordered_set>    // Include for handling uniqe variable
#include <cctype>           // This is for including digit charachters
#include <vector>           // Include the vector library
#define _USE_MATH_DEFINES   // Include using mataematical constant such as PI



using namespace std;        // using namespace to avoid writing "std"


// Here is the class start our cllass called math_symboles
class math_symboles {
private:
    // This Function is  check  precedence of opereators  and function
    int precedence(const string& symbol) {
        if (symbol == "^") {
            return 4;       // Here the  exponent  highest  precedence
        } else if (symbol == "*" || symbol == "/") {
            return 3;       // Division and multiplication are highest  precedence
        } else if (symbol == "+" || symbol == "-") {
            return 2;       // Additon and sutruction have the lowest precedence
        } else if (symbol == "(") {
            return 1;       // Here parantise special  precedence
        } else {
            return 0;       // Invalid character
        }
    }


    bool check_numbers(const string& str) {
        char* end = nullptr;
        strtod(str.c_str(), &end);          // Here converting string to a double
        return end == &str[str.size()];     // Here is  checking if the straing was a number
    }

    // Function for checking if the character is decimal pint  or digit
    bool check_isOperand(char ch) {
        return isdigit(ch) || ch == '.';    // will return true if it is deciaml or number
    }

     // This Function which is checking correct operetors and mismatched parenthese
    bool isthis_correct(const string& infix) {
        int barcket_counts = 0;     // This counter  parenthese
        char last_char = '\0';      // last character trackinig
        for (size_t i = 0; i < infix.length(); i++) {
            char The_current = infix[i];
            if (The_current == '(') barcket_counts++;           // Here raise the amount for the first parenthesis
            else if (The_current == ')') barcket_counts--;      //This line drop counts as the end of the parenthesis.
            if (barcket_counts < 0) return false;               //If closed braces come after opening ones, that's a mistake.


            //This function looks for letters that aren't allowed in the statement.
            if (!isdigit(The_current) && !isalpha(The_current) && !isspace(The_current) &&
                The_current != '+' && The_current!= '-' && The_current != '*' &&
                The_current != '/' && The_current != '^' && The_current != '(' && The_current != ')'
                && The_current!= '.') {
                return false;  // function will return false.
            }


            // See if two operators (like ++ and --) are next to each other.
            if ((The_current== '+' || The_current == '-' || The_current == '*' || The_current == '/' ||The_current == '^') &&
                (last_char == '+' || last_char  == '-' || last_char == '*' ||last_char == '/' || last_char  == '^')) {
                return false;  // for consecutive operators, return false.
            }

            if (!isspace(The_current)) last_char  = The_current;
        }
        return barcket_counts == 0;
    }

    //Working with numbers, negative signs, and decimal points.
    vector<string> split_into_parts(const string& str) {
        vector<string> split;
        size_t i = 0;
        while (i < str.length()) {
            if (isspace(str[i])) {
                i++;
                continue;
            }
            if (check_isOperand(str[i]) || (str[i] == '-' && i + 1 < str.length() && isdigit(str[i + 1]))) {

                string num;
                while (i < str.length() && (check_isOperand(str[i]))) {
                    num += str[i];
                    i++;
                }
                split.push_back(num);
            } else if (isalpha(str[i])) {

                //Functions to handle: sin, cos, pi etc.
                string name;
                while (i < str.length() && isalpha(str[i])) {
                    name += str[i];
                    i++;
                }
                if (name == "pi") {
                    split.push_back(to_string(M_PI));
                } else {
                    split.push_back(name);
                }
            } else {
                split.push_back(string(1, str[i]));
                i++;
            }
        }
        return split;
    }




public:
    // In this will convert infix to postfix expression
    string infixToPostfix(const string& infix, unordered_set<string>& variables) {
        stack<string> stack_list;
        string postfix;
        vector<string> split= split_into_parts(infix);

        for (size_t i = 0; i < split.size(); i++) {
            string token = split[i];

            // check the token if it's number or pi, appned it to postfix expresions
            if (check_numbers(token) || token == to_string(M_PI)) {
                postfix += token + ' ';
            }
            else if (isalpha(token[0])) {

                // Here will ahndele the functions such as sin, cos and log
                if (token == "sin" || token == "cos" || token == "log") {

                    if (i + 1 < split.size() && split[i + 1] == "(") {
                        stack_list.push(token);
                        stack_list.push(split[++i]);
                    } else {
                        cout << "Error: Expected '(' after function '" << token << "'." << endl;
                        return "";
                    }
                } else {
                    // Adding variables to the postfix expression and set.
                    postfix += token + ' ';
                    variables.insert(token);
                }
            }
            else if (token == "(") {
                stack_list.push(token);
            }
            else if (token == ")") {
                // Here will pop until maching '(' is found.
                while (!stack_list.empty() && stack_list.top() != "(") {
                    postfix += stack_list.top() + ' ';
                    stack_list.pop();
                }
                if (stack_list.empty()) {
                    cout << "Error: Mismatched parentheses." << endl;
                    return "";
                }
                stack_list.pop(); // Pop '('


                if (!stack_list.empty() && (stack_list.top() == "sin" || stack_list.top() == "cos" || stack_list.top() == "log")) {
                    postfix += stack_list.top() + ' ';
                    stack_list.pop();
                }
            }
            else {
                // Operator
                while (!stack_list.empty() && precedence(stack_list.top()) >= precedence(token)) {
                    postfix += stack_list.top() + ' ';
                    stack_list.pop();
                }
                stack_list.push(token);
            }
        }


        //Pop all remaining operators.
        while (!stack_list.empty()) {
            if (stack_list.top() == "(") {
                cout << "Error: Mismatched parentheses." << endl;
                return "";
            }
            postfix += stack_list.top() + ' ';
            stack_list.pop();
        }
        return postfix;
    }

    //Evaluates a postfix expression and returns the result.
    double calculate_postfix(const string& postfix) {
        stack<double> stack_2;
        vector<string> split = split_into_parts(postfix);

        for (const string& index : split) {
            if (check_numbers(index)) {
                stack_2.push(stod(index));
            }
            else if (index == to_string(M_PI)) {
                stack_2.push(M_PI);
            }
            else if (index == "sin" || index == "cos" || index == "log") {
                if (stack_2.empty()) {
                    cout << "Error: Insufficient operands for function " << index << endl;
                    return 0;
                }
                double operand = stack_2.top(); stack_2.pop();
                if (index == "sin") stack_2.push(sin(operand));
                else if (index == "cos") stack_2.push(cos(operand));
                else if (index == "log") stack_2.push(log10(operand));
            }
            else if (index == "+" || index == "-" || index == "*" || index == "/" || index == "^") {
                if (stack_2.size() < 2) {
                    cout << "Error: Insufficient operands for operator " << index << endl;
                    return 0;
                }
                double op2 = stack_2.top(); stack_2.pop();
                double op1 = stack_2.top(); stack_2.pop();
                if (index == "+") stack_2.push(op1 + op2);
                else if (index == "-") stack_2.push(op1 - op2);
                else if (index == "*") stack_2.push(op1 * op2);
                else if (index == "/") stack_2.push(op1 / op2);
                else if (index == "^") stack_2.push(pow(op1, op2));
            }
            else {
                cout << "Error: Undefined variable or function '" << index << "' in evaluation." << endl;
                return 0;
            }
        }
        return stack_2.empty() ? 0 : stack_2.top();
    }



    //Main function to read the expression, convert, and calculate it
    void calculate() {
        string infix_expo, postfix_expo;
        cout << "Please enter an expression" << endl;
        getline(cin, infix_expo);


        if (!isthis_correct(infix_expo)) {
            cout << "Invalid expression! Please use valid operators and ensure parentheses are matched." << endl;
            return;
        }

        unordered_set<string> variables;
        postfix_expo = infixToPostfix(infix_expo, variables);

        if (postfix_expo.empty()) {

            return;
        }

        cout << "The postfix expression is: " << postfix_expo << endl;

        if (variables.empty()) {
            //If no variables, find the product.
            double result = calculate_postfix(postfix_expo);
            cout << "The result is: " << result << endl;
        } else {
            //If there are variables, let the user know.
            cout << "Note: Expression contains variables. Evaluation is not performed." << endl;
        }
    }
};

int main() {
     math_symboles  exprProcessor;  //Create an object class math_symboles.

    exprProcessor.calculate();  // Call the function calculate to start the operation.

    return 0;
}
