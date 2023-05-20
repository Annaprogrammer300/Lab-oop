#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace function;
using namespace std;


float Function::get_a() const {
    return _a;
}

float Function::get_b() const {
    return _b;
}

float Function::get_c() const {
    return _c;
}



float Log::compute_value(float const x) const {
    return _c * log(abs(x));
}

float Log_pp::compute_value(float const x) const {
    return _c * (x * log(x) - x);
}

float Power::compute_value(float const x) const {
    return _a * pow(x, _b);
}



FunctionPtr Log::compute_derivative() const {
    return std::make_shared<Power>( _c, -1);
}

FunctionPtr Power::compute_derivative() const {
    return  std::make_shared<Power>(_a * _b, _b - 1);
}



FunctionPtr Log::compute_antiderivative() const {
    return std::make_shared<Log_pp>(_c);
}

FunctionPtr Power::compute_antiderivative() const {
    if (_b == -1)
        return std::make_shared<Log>(_a);
    return std::make_shared<Power>(_a / (_b + 1), _b + 1);
}



void Power::print()const {
    cout<< " �������:  " << _a << " � ^ " << _b << " \n " << endl;
}

void Log::print()const {
    cout << " �������:  " << _c << " ln �" << " \n " << endl;
}



FunctionPtr Log::clone() const {
    return make_shared<Log>(_c);
}

FunctionPtr Power::clone() const {
    return make_shared<Power>(_a,_b);
}

FunctionPtr Log_pp::clone() const {
    return make_shared<Log>(_c);
}
