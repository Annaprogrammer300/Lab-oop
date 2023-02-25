#pragma once

namespace function {

	const float E = 2.718f;

	enum class Type {
		log,
		power

	};

	class Function {
	private:
		Type _type;
		float _a;
		float _b;
		float _c;

		Function(Type type, float a);

	public:
		static Function create_log(float a);
		static Function create_power(float a);

		Function();
		Type get_type() const;//получать тип
		float get_a() const;//получать а
		float get_c() const;
		float compute_value(float x, float b) const;//вфчислить значение

		Function compute_derivative() const;//вычислить производную

	};

	bool operator==(const Function& Ihs, const Function rhs);
	bool operator!=(const Function& Ihs, const Function rhs);


	class Functionlist {
	public:
		static const int CAPACITY = 10;
	private:
		Function _function[CAPACITY];
		int _size;
	public:
		Functionlist();
		int size() const;
		Function operator[](int index) const;
		void add(Function f);
	};

	int index_of_min_value(const Functionlist& function, float x);

}
