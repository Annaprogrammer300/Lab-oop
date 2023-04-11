#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>



using namespace function;
using namespace std;



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
