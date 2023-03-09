#include <Function1/Function1.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace function;
using namespace std;

Function::Function(float ñ, float x) {
    _type = function::Type::log;
    _c = ñ;
    _x = abs(x);
}

Function::Function(float a, float x, float b) {
    _type = function::Type::power;
    _a = a;
    _x = x;
    _b = b;
}


Type Function::get_type() const {
    return _type;
}

float Function::get_a() const {
    return _a;
}

float Function::get_b() const {
    return _b;
}

float Function::get_c() const {
    return _c;
}

float Function::compute_value() const {
    switch (_type) {
    case Type::log:
        return _c * log(_x);
    case Type::power:
        return _a * pow(_x, _b);
    default:
        throw runtime_error("[Function::compute_value] Invalid function type.");
    }
}

float Function::compute_derivative() const {
    switch (_type) {
    case Type::log:
        return _c * (1 / _x);
    case Type::power:
        return _a * pow(_x, _b - 1);
    default:
        throw runtime_error("[Function::compute_derivative] Invalid function type.");
    }
}

float Function::compute_antiderivative() const {
    switch (_type) {
    case Type::log:
        return _c * (log(_x) - _x);
    case Type::power:
        return _a * (pow(_x, _b + 1) / (_x + 1));
    default:
        throw runtime_error("[Function::compute_antiderivative] Invalid function type.");
    }
}