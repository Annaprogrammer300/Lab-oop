#include <Function1/Function1.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace function;
using namespace std;

Function Function::create_log(const float a) {
    return Function(Type::log, a);
}

Function Function::create_power(const float a) {
    return Function(Type::power, a);
}
Function::Function() : _type(Type::log), _a(1) { }

Function::Function(const Type type, const float a) : _type(type), _a(a) { }

Type Function::get_type() const {
    return _type;
}

float Function::get_a() const {
    return _a;


}
float Function::get_c() const {
    return _c;
}

float Function::compute_value(const float x, const float b) const {
    switch (_type) {
    case Type::log:
        return _c * log(x);
    case Type::power:
        return _a * pow(x, b);
    default:
        throw runtime_error("[Function::compute_value] Invalid function type.");
    }
}

Function Function::compute_derivative() const {
    switch (_type) {
    case Type::log:
        return create_log(1/_a);
    case Type::power:
        return create_power(_b*_a^(_b-1));
    default:
        throw runtime_error("[Function::compute_derivative] Invalid function type.");
    }
}