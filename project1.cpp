#include <iostream>
#include <cmath>



// returns false if the number is int , true if it is deciaml
bool is_num_decimal(std::string string) {
    // better solution string.find('.') != std::string::npos , just to learn
    // it can be fully simplified as :  return (string.find('.') != std::string::npos);

    for (const char c : string)
        if (c == '.') return true;

    return false;


};


void read_operation(double& operand1 , double& operand2 , char& operation, bool& has_decimal) {
    std::string temp;

    // first operand input , checking for deciaml part and saving
    std::cout << "First operand: \n" ;
    std::cin >> temp;
    has_decimal |= is_num_decimal(temp);
    operand1 = std::stod(temp);

    do {
        std::cout << "Select one of the supported operations  : + - * / %\n";
        std::cin >> temp;
    }
    while (temp != "+" && temp != "-" && temp != "/" && temp != "%");

    operation = temp[0];

    // second oprenad reading , checking for deciaml part and saving
    std::cout << "Second operand: \n" ;
    std::cin >> temp;
    has_decimal |= is_num_decimal(temp);
    operand2 = std::stod(temp);

};

bool valid_divisor(const double operand2) {
    if (operand2 <= 0.0) {
        std::cout << "The operand 2 for division must be  higher than 0 \n";
        std::cout << "Try again in a new operation \n";
        return false;
    }
    return true;

};

double calculate(const double& operand1 ,const double& operand2 ,const char& operation) {
    switch (operation) {
            // i do not use break at the end of each case because they only manage return statementes
            // (execution of the loop is ended)
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '/':
                if (valid_divisor(operand2)) return operand1 / operand2;
                break;
            case '*': return operand1 * operand2;
            case '%': return fmod(operand1, operand2);
            default: std::cout << "The operation " << operation << " is not supported."; break;
        }
    return -1;
};

void show_result(double& result, const bool& has_decimal) {
    if (!has_decimal)
        result = static_cast<int>(result);
    std::cout << "Result:  " << result << " \n";
};

int main() {

    // variables
    double operand1;
    double operand2;
    char operation;     //+ - / * %
    bool has_decimal;   //0 no operand is decimal , >0 at least one operand is decimal
    double result;

    // program
    std::string input {"a"};
    std::cout << "do you want to make new operation (y/n):\n";
    std::cin >> input;

    while (input != "q") {

        if (input == "y") {
            read_operation(operand1, operand2, operation, has_decimal);
            result = calculate(operand1, operand2, operation);
            show_result(result, has_decimal);
        }

        std::cout << "do you want to make another operation (y/n):\n";

        std::cin >> input;
    }

    return 0;
}

