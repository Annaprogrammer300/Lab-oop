#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>



using namespace function;
using namespace std;



function::FunctionList::FunctionList(): _list(nullptr), _size(0) {}

FunctionList::FunctionList(const FunctionList& copy) :
    _list(new Function* [copy._size]),
    _size(copy._size)
{
    for (int i = 0; i < _size; ++i)
        _list[i] = new Function(*copy._list[i]);
}

void FunctionList::swap(FunctionList& rhs) noexcept
{
    std::swap(_size, rhs._size);
    std::swap(_list, rhs._list);
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
    if(_list == nullptr)
        return;

    for (int i = 0; i < _size; ++i)
        delete _list[i];
    _size = 0;
    delete[] _list;
    _list = nullptr;
}

int FunctionList::get_size() const {
    return _size;
}

const Function& FunctionList::operator[](int index) const {
    if (index < 0 || index >= _size) {
        throw out_of_range("[FunctionList::operator[] Index is out of range.");
    }
    return *_list[index];
}


Function& FunctionList::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw out_of_range("[FunctionList::operator[] Index is out of range.");
    }
    return *_list[index];
}

void FunctionList::insert(int index, Function f) {
    
    if (index < 0 || _size <= index)
        throw runtime_error("[FunctionList::insert] Index is out of range.");
    auto list = new Function * [_size + 1];

    for (int i = 0; i < _size; ++i)
        list[i] = _list[i];

    for (int i = _size; i > index; --i)
        list[i] = list[i - 1];
    list[index] = new Function(f);

    delete[] _list;
    _list = list;
    _size++;
}

void FunctionList::add(const Function& f) {

    auto list = new Function * [_size + 1];

    for (int i = 0; i < _size; ++i)
        list[i] = _list[i];

    list[_size] = new Function(f);
    delete[] _list;
    _list = list;
    _size++;

}

void FunctionList::remove(int index) {
    if (index < 0 || index >= _size) {

        throw runtime_error("[Func_list::remove Func_list is empty");
    }

    delete _list[index];
    for (int i = index; i < _size - 1; i++)
        _list[i] = _list[i + 1];
    --_size;
}


std::ostream& function::operator<<(std::ostream& stream, const FunctionList& list) {
    stream << list.get_size() << " функции: " << endl;
    for (int i = 0; i < list.get_size(); ++i)
        cout << "  " << i + 1 << ") " << list[i];
    return stream;
}

int FunctionList::last_min(const double x) {
    if (_size == 0)
        return -1;
    float mvalue = _list[0]->compute_derivative().compute_value(x);
    int mindex = 0;
    for (int i = 1; i < _size; i++) {
        float curr = _list[i]->compute_derivative().compute_value(x);
        if (mvalue >= curr) {
            mindex = i;
            mvalue = curr;
        }
    }
    return mindex;
}
