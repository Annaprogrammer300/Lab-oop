#include <Function1/Function1.h>

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <string>




using namespace function;
using namespace std;


//Function::Function() : _type(Type::power), _a(0), _b(0), _c(0) {}
//
//Function::Function(Type type, float c) : _c(c), _a(0), _b(0) {
//    _type = type;
//}
//
//
//Function::Function(Type type, float a, float b) : _a(a), _b(b), _c(0) {
//    _type = type;
//}
//
//Type Function::get_f_type() const {
//    return _type;
//}
//
//std::string Function::get_type() const {
//    switch (_type)
//    {
//    case Type::log:
//        return "Log";
//    case Type::power:
//        return "Power";
//    default:
//        throw runtime_error("Unknown type");
//    }
//}

float Function::get_a() const {
    return _a;
}

float Function::get_b() const {
    return _b;
}

float Function::get_c() const {
    return _c;
}

//void Function::print() const {
//}

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
    cout<< " Функция:  " << _a << " х ^ " << _b << " \n " << endl;
}

void Log::print()const {
    cout << " Функция:  " << _c << " ln х" << " \n " << endl;
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

//float Function::compute_value(float const x) const {
//    switch (_type) {
//    case Type::log:
//        return _c * log(abs(x));
//    case Type::power:
//        return _a * pow(x, _b);
//    case Type::log_pp:
//        return _c * (x * log(x) - x);
//    default:
//        throw runtime_error("[Function::compute_value] Invalid function type.");
//    }
//}
//
//Function Function::compute_derivative() const {
//    switch (_type) {
//    case Type::log:
//        return Function(Type::power, _c, -1);
//    case Type::power:
//        return Function(Type::power, _a * _b, _b - 1);
//    default:
//        throw runtime_error("[Function::compute_derivative] Invalid function type.");
//    }
//}
//
//Function Function::compute_antiderivative() const {
//    switch (_type) {
//    case Type::log:
//        return Function(Type::log_pp, _c);
//    case Type::power:
//        if(_b==-1)
//            return Function(Type::log, _a);
//        return Function(Type::power, _a / (_b + 1), _b + 1);
//    default:
//        throw runtime_error("[Function::compute_antiderivative] Invalid function type.");
//    }
//}

//std::ostream& function::operator<<(std::ostream& stream, const Function& f) {
//    if (f.get_type() == "Power")
//        stream << "Тип функции:  " << f.get_type() << "  " << f.get_a() << " х ^ " << f.get_b() << " \n " << endl;
//       
//    else
//        stream << "Тип функции :  " << f.get_type() << "  " << f.get_c() << " ln х" << " \n "<< endl;
//    return stream;
//}





