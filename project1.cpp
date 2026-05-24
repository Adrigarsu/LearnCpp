#include <iostream>

double operand1;
double operand2;
char operation;     //+ - / * %
bool has_decimal;   //0 no operand is decimal , >0 at least one operand is decimal

// returns false if the number is int , true if it is deciaml
bool is_num_decimal(std::string string) {
    if (string.find('.') != std::string::npos)
        return true;
    return false;
    // se puede simplificar en return (string.find('.') != std::string::npos);
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




    // second oprenad reading , checking for deciaml part and saving
    std::cout << "Second operand: \n" ;
    std::cin >> temp;
    has_decimal |= is_num_decimal(temp);
    operand2 = std::stod(temp);

};

void calculate(){};
void show_result(){};

int main() {
    std::string input {"a"};
    std::cout << "Input a new operation:\n";
    std::cin >> input;

    while (input != "q") {
        read_operation();

    }

    return 0;
}

