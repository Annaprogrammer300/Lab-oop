#pragma once

namespace function {

	//const float E = 2.718f;

	enum class Type {
		log,
		power,
		log_p,
		log_pp

	};

	class Function {
	private:
		Type _type;
		float _a;
		float _b;
		float _c;
		//float _x;//убрать так как это не параметры функции

		//Function(Type type);

	public:
		Function();
		Function(Type type, float a, float b);
		Function(Type type, float c);
		Type get_type() const;//получать тип
		float get_a() const;//получать а
		float get_b() const;
		float get_c() const;
		float compute_value(float x) const;//вычислить значение
		Function compute_derivative() const;//вычислить производную
		Function compute_antiderivative() const;


	};

	//надо подумать

	//надо найти минимальны элемент в функции проихводной с данным аргументом
	class FunctionList {
	public:
		static const int N = 10;
		FunctionList();
		int get_size() const;
		Function operator[](int index) const;
		void add(const Function& _F);
		int last_min(const double x);
	private:
		Function listf[N];
		int _size;
	};
}
