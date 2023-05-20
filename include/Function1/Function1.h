#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <memory>
#include <vector>


namespace function {

	class Function;
	using FunctionPtr = std::shared_ptr<Function>;

	class Function {
	public:
		Function(){};
		virtual void print() const = 0;
		virtual FunctionPtr clone() const = 0;

		virtual float compute_value(float x) const = 0;//вычислить значение
		virtual FunctionPtr compute_derivative() const = 0;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const = 0;


	};

	class Log: public Function {
	protected:
		float _c;
	public:
		//Log() : Function() {}
		Log() : _c(0) {}
		Log(float c) : _c(c){}

		float get_c() const;

		void print() const override;
		FunctionPtr clone() const override;

		virtual float compute_value(float x) const override;//вычислить значение
		virtual FunctionPtr compute_derivative() const override;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const override;

	};

	class Power : public Function {
	private:
		float _a;
		float _b;
	public:
		//Power(): Function() {}
		Power() : _a(0),_b(0) {}
		Power(float a, float b) : _a(a), _b(b) {}
		float get_a() const;//получать а
		float get_b() const;

		void print() const override;
		FunctionPtr clone() const override;

		virtual float compute_value(float x) const override;//вычислить значение
		virtual FunctionPtr compute_derivative() const override;//вычислить производную
		virtual FunctionPtr compute_antiderivative() const override;

	};

	class Log_primordial : public Function {//primordial
	protected:
		float _c;
	public:
		Log_primordial() : Function() {}
		Log_primordial(float c) : Function(), _c(c) {}
		FunctionPtr clone() const override;
		void print() const override;

		virtual float compute_value(float x) const override;
		virtual FunctionPtr compute_derivative() const override;
		virtual FunctionPtr compute_antiderivative() const override;
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
