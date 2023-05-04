#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>




using namespace function;
using namespace std;


Function::Function() : _type(Type::power), _a(0), _b(0), _c(0) {}

Function::Function(Type type, float c) : _c(c), _a(0), _b(0) {
    _type = type;
}


Function::Function(Type type, float a, float b) : _a(a), _b(b), _c(0) {
    _type = type;
}

Type Function::get_f_type() const {
    return _type;
}

std::string Function::get_type() const {
    switch (_type)
    {
    case Type::log:
        return "Log";
    case Type::power:
        return "Power";
    default:
        throw runtime_error("Unknown type");
    }
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


float Function::compute_value(float const x) const {
    switch (_type) {
    case Type::log:
        return _c * log(abs(x));
    case Type::power:
        return _a * pow(x, _b);
    case Type::log_pp:
        return _c * (x * log(x) - x);
    default:
        throw runtime_error("[Function::compute_value] Invalid function type.");
    }
}

Function Function::compute_derivative() const {
    switch (_type) {
    case Type::log:
        return Function(Type::power, _c, -1);
    case Type::power:
        return Function(Type::power, _a * _b, _b - 1);
    default:
        throw runtime_error("[Function::compute_derivative] Invalid function type.");
    }
}

Function Function::compute_antiderivative() const {
    switch (_type) {
    case Type::log:
        return Function(Type::log_pp, _c);
    case Type::power:
        if(_b==-1)
            return Function(Type::log, _a);
        return Function(Type::power, _a / (_b + 1), _b + 1);
    default:
        throw runtime_error("[Function::compute_antiderivative] Invalid function type.");
    }
}

std::ostream& function::operator<<(std::ostream& stream, const Function& f) {
    if (f.get_type() == "Power")
        stream << "��� �������:  " << f.get_type() << "  " << f.get_a() << " � ^ " << f.get_b() << " \n " << endl;
       
    else
        stream << "��� ������� :  " << f.get_type() << "  " << f.get_c() << " ln �" << " \n "<< endl;
    return stream;
}





