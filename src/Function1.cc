#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>



using namespace function;
using namespace std;


Function::Function(float a, float x, float b):  _a(a), _x(x), _b(b) {
    _type = function::Type::power;
}

Function::Function(float c, float x):  _x(x), _c(c) {
    _type = function::Type::log;
}

Function::Function() : _a(0), _x(0), _b(0), _c(0) {
    _type = function::Type::power;
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

float Function::get_x() const {
    return _x;
}

float Function::compute_value() const {
    switch (_type) {
    case Type::log:
        return _c * log(abs(_x));
    case Type::power:
        return _a * pow(_x, _b);
    //default:
    //    throw runtime_error("[Function::compute_value] Invalid function type.");
    }
}

float Function::compute_derivative() const {
    switch (_type) {
    case Type::log:
        return _c * (1 / _x);
    case Type::power:
        return _a * _b* pow(_x, _b - 1);
   // default:
    //    throw runtime_error("[Function::compute_derivative] Invalid function type.");
    }
}

float Function::compute_antiderivative() const {
    switch (_type) {
    case Type::log:
        return _c * (_x * log(_x) - _x);
    case Type::power:
        return _a * (pow(_x, _b + 1) / (_b + 1));
   // default:
    //    throw runtime_error("[Function::compute_antiderivative] Invalid function type.");
    }


}
Container::Container() {
    corsize = 5;
    for (int i = 0; i < corsize; ++i) {
        listf[i] = Function();
    }
}

Container::Container(Function s[], int size) {
    corsize = size;
    for (int i = 0; i < corsize; i++) {
        listf[i] = s[i];
    }
}


int Container::get_size() const {
    return corsize;
}


void Container::appendel(int n, Function a) {
    if (0 > n || n >= N) {
        throw runtime_error("ERROR. Index out of range.");
    }
    if (corsize == N) {
        throw runtime_error("ERROR. Array is full.");
    }
    for (int i = n + 1; i < corsize; i++) {
        listf[i] = listf[i + 1];
    }
    listf[n] = a;
    corsize++;

}

void Container::dellel(int n) {
    if (0 > n || n >= N) {
        throw runtime_error("ERROR. Index out of range.");
    }
    if (corsize == N) {
        throw runtime_error("ERROR. Array is full.");
    }
    for (int i = n; i < corsize; i++) {
        listf[i] = listf[i + 1];
    }
    corsize--;
}

Function& Container::operator[](int n) {
    if (0 > n || n >= N) {
        throw runtime_error("ERROR. Index out of range.");
    }
    return listf[n];
    corsize++;
}

Function Container::operator[](int n) const {
    return listf[n];
}


Function Container::find_min_derivative() {
    int indexminel = 0;
    Function arr[1];
    arr[0] = listf[0];
    for (int i = 1; i < corsize; ++i) {
        if (listf[i].compute_derivative() < arr[0].compute_derivative()) {
            arr[0] = listf[i];
            indexminel = i;
        }
    }

    return listf[indexminel];
}