#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>



using namespace function;
using namespace std;



function::FunctionList::FunctionList(): listf(nullptr), _size(0) {}

FunctionList::FunctionList(const FunctionList& copy) :
    listf(new Function* [copy._size]),
    _size(copy._size)
{
    for (int i = 0; i < _size; ++i)
        listf[i] = new Function(*copy.listf[i]);
}

void FunctionList::swap(FunctionList& rhs) noexcept
{
    std::swap(_size, rhs._size);
    std::swap(listf, rhs.listf);
}

FunctionList& FunctionList::operator=(FunctionList copy)
{
    swap(copy);
    return *this;
}

FunctionList::~FunctionList()
{
    clear();
}

void FunctionList::clear() {
    if(listf == nullptr)
        return;

    for (int i = 0; i < _size; ++i)
        delete listf[i];
    _size = 0;
    delete[] listf;
    listf = nullptr;
}

int FunctionList::get_size() const {
    return _size;
}

const Function& FunctionList::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw out_of_range("[FunctionList::operator[] Index is out of range.");
    }
    return *listf[index];
}


Function& FunctionList::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw out_of_range("[FunctionList::operator[] Index is out of range.");
    }
    return *listf[index];
}

void FunctionList::insert(int index, Function f) {
    /*if (_size <= index || index <= 0)
        throw runtime_error("[Func_list::insert] Going outside the array");*/
    if (index < 0 || _size <= index)
        throw runtime_error("[Func_list::insert] Index is out of range.");
    auto list = new Function * [_size + 1];

    for (int i = 0; i < _size; ++i)
        list[i] = listf[i];

    for (int i = _size; i > index; -i)
        list[i] = list[i - 1];
    list[index] = new Function(f);

    delete[] listf;
    listf = list;
    _size++;
}

void FunctionList::add(const Function& f) {

    auto list = new Function * [_size + 1];

    for (int i = 0; i < _size; ++i)
        list[i] = listf[i];

    list[_size] = new Function(f);
    delete[] listf;
    listf = list;
    _size++;

}

void FunctionList::remove(int index) {
    if (index < 0 || index >= _size) {
        throw runtime_error("[Func_list::remove Func_list is empty");
    }

    delete listf[index];
    for (int i = index; i < _size - 1; i++)
        listf[i] = listf[i + 1];
    --_size;
}


std::ostream& function::operator<<(std::ostream& stream, const FunctionList& list) {
    stream << list.get_size() << " Функции: " << endl;
    for (int i = 0; i < list.get_size(); ++i)
        cout << "  " << i + 1 << ") " << list[i];
    return stream;
}

int FunctionList::last_min(const double x) {
    if (_size == 0)
        return -1;
    float mvalue = listf[0]->compute_derivative().compute_value(x);
    int mindex = 0;
    for (int i = 1; i < _size; i++) {
        float curr = listf[i]->compute_derivative().compute_value(x);
        if (mvalue >= curr) {
            mindex = i;
            mvalue = curr;
        }
    }
    return mindex;
}
