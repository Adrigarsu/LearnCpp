//
// Created by adrig on 26/05/2026.
//

#include "basic.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace mathlib::basic {
    double sum(const double op1, const double op2) {
        return op1+op2;
    };
    double sub(const double op1, const double op2) {
        return op1 - op2;
    };
    double div(const double op1, const double op2) {
        if (op2 == 0 ){ std::cout << "The second operand must be different from 0"; return 0;};
        return op1 / op2;
    };
    double mul(const double op1, const double op2) {
        return op1*op2;
    };
    double mod(const double op1, const double op2) {
        return fmod(op1, op2);
    };
}
