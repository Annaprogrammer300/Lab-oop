#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>



using namespace function;
using namespace std;


Function::Function() : _a(0), _b(0), _c(0) {}

Function::Function(Type type, float c) : _c(c), _a(0), _b(0) {
    _type = type;
}

//что надо сделать с переменной х, это не пармаметр функции0
Function::Function(Type type, float a, float b) : _a(a), _b(b), _c(0) {
    _type = type;
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


float Function::compute_value(float const x) const {
    switch (_type) {
    case Type::log:
        return _c * log(abs(x));
    case Type::power:
        return _a * pow(x, _b);
    case Type::log_p:
        if(x==0)
            throw invalid_argument("[Function::compute_value] proizosholo delenie na 0.");
        else
        return _c * (1/x);
    case Type::log_pp:
        return _c * (x * log(x) - x);
    default:
        throw runtime_error("[Function::compute_value] Invalid function type.");
    }
}

Function Function::compute_derivative() const {
    switch (_type) {
    case Type::log:
        return Function(Type::log_p, _c);
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
            return Function(Type::log, 1);
        else
        return Function(Type::power, _a / (_b + 1), _b + 1);
    default:
        throw runtime_error("[Function::compute_antiderivative] Invalid function type.");
    }
}




function::FunctionList::FunctionList() {
    _size = 0;
}

int FunctionList::get_size() const {
    return _size;
}

Function FunctionList::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw out_of_range("[FunctionList::operator[]] Index is out of range.");
    }
    return listf[index];
}


void FunctionList::add(const Function& _F) {

    if (_size == N) {
        throw runtime_error("ERROR. Array is full.");
    }
    
    listf[_size] = _F;
    _size++;

}


int FunctionList::last_min(const double x) {
    Function vrem1 = listf[0];
    Function vrem2 = vrem1.compute_derivative();
    float mvalue = vrem2.compute_value(x);
    int mindex = 0;
    for (int i = 0; i < _size; i++) {
        vrem1 = listf[i];
        vrem2 = vrem1.compute_derivative();
        if (mvalue >= vrem2.compute_value(x)) {
            mindex = i;
            mvalue = vrem2.compute_value(x);
        }
    }
    return mindex;

}




