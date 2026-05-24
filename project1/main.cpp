#include <iostream>
#include <cmath>


struct Operation {
    double operand1;
    double operand2;
    char operation;
    double result; // -1 if the result is an error
};


// returns false if the number is int , true if it is decimal
bool is_num_decimal(std::string string) {
    // better solution string.find('.') != std::string::npos , just to learn
    // it can be fully simplified as :  return (string.find('.') != std::string::npos);

    for (const char c : string)
        if (c == '.') return true;

    return false;


};


void read_operation(double& operand1 , double& operand2 , char& operation, bool& has_decimal) {
    std::string temp;
    has_decimal = false; // reset before each operation

    // first operand input , checking for decimal part and saving
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

    // second operand reading , checking for decimal part and saving
    std::cout << "Second operand: \n" ;
    std::cin >> temp;
    has_decimal |= is_num_decimal(temp);
    operand2 = std::stod(temp);

};

bool valid_divisor(const double operand2) {
    if (operand2 == 0.0) {
        std::cout << "The operand 2 for division must be  different than 0 \n";
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


void save_result(Operation * history, const Operation & op, int& op_count) {
    history[op_count] = op;
    ++op_count;
};

void show_history(const Operation * history, const int op_count ) {
    std::cout << "HISTORY \n";
    for (int i = 0; i < op_count; i++) {
        std::cout << "Operation " << i+1 << " : ";
        std::cout << history[i].operand1 << " " << history[i].operation << " " << history[i].operand2 << " = ";
        if (history[i].result != -1)
            std::cout << history[i].result << "\n";
        else {
            std::cout << "Error in operation \n";
        }

    }
    std::cout << "\n";
};

int main() {

    // variables
    double operand1;
    double operand2;
    char operation;     //+ - / * %
    bool has_decimal;   //0 no operand is decimal , >0 at least one operand is decimal
    double result;

    constexpr int history_size = 10;
    Operation history[history_size];
    int op_count = 0 ;


    // program
    std::string input {"a"};
    std::cout << "do you want to make new operation (y/n):\n";
    std::cin >> input;

    while (input != "q") {

        if (input == "h") {
            show_history(history, op_count);
        }

        if (input == "y" ) {
            if (op_count >= history_size) {
                std::cout << "No more opeartions can be saved in the history";
                break;
            }
            read_operation(operand1, operand2, operation, has_decimal);
            result = calculate(operand1, operand2, operation);
            show_result(result, has_decimal);
            Operation op = {operand1, operand2, operation, result};
            save_result(history, op, op_count);

        }

        std::cout << "do you want to make another operation (y/n) \n";
        std::cout << "press q to quit and h to view the history \n";
        std::cin >> input;
    }

    return 0;
}

