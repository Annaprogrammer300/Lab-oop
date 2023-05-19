#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <memory>
#include <vector>


namespace function {

	/*enum class Type {
		log,
		power,
		log_pp

	};*/

	class Function;
	using FunctionPtr = std::shared_ptr<Function>;

	class Function {
	protected:
		float _a;
		float _b;
		float _c;//можно убрать эту пременную

	public:
		Function(): _a(0), _b(0), _c(0) {};
		Function(float a, float b) : _c(0), _a(a), _b(b) {};
		Function( float c): _c(c), _a(0), _b(0) {};
		float get_a() const;//получать а
		float get_b() const;
		float get_c() const;
		virtual void print() const = 0;
		virtual FunctionPtr clone() const = 0;

		virtual float compute_value(float x) const = 0;//вычислить значение
		virtual FunctionPtr compute_derivative() const = 0;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const = 0;


	};

	class Log: public Function {
	public:
		Log() : Function() {}
		Log(float c) : Function(c){}

		void print() const override;
		FunctionPtr clone() const override;

		virtual float compute_value(float x) const override;//вычислить значение
		virtual FunctionPtr compute_derivative() const override;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const override;

	};

	class Power : public Function {
	public:
		Power() : Function() {}
		Power(float a, float b) : Function(a, b) {}

		void print() const override;
		FunctionPtr clone() const override;

		virtual float compute_value(float x) const override;//вычислить значение
		virtual FunctionPtr compute_derivative() const override;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const override;

	};

	class Log_pp : public Log {
	public:
		Log_pp() : Log() {}
		Log_pp(float c) : Log(c) {}
		FunctionPtr clone() const override;

		virtual float compute_value(float x) const override;
	};

	class FunctionList {
		std::vector<FunctionPtr> _list;
	public:
		//static const int N = 10;
		FunctionList() = default;
		FunctionList(const FunctionList& copy);
		FunctionList& operator=(FunctionList copy);
		FunctionPtr& operator[](int index);
		const FunctionPtr& operator[](int index) const;
		int get_size() const;


		void swap(FunctionList& rhs);
		void insert(int index, FunctionPtr f);
		void add( FunctionPtr _F);
		int last_min(const double x);
		void remove(int index);
		void clear();
		void print();
	
	};

}
