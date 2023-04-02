#pragma once

namespace function {

	//const float E = 2.718f;

	enum class Type {
		log,
		power,

	};

	class Function {
	private:
		Type _type;
		float _a;
		float _b;
		float _c;
		float _x;//убрать так как это не параметры функции

		//Function(Type type);

	public:
		Function();
		Function(float a, float x, float b);
		Function(float x, float c);
		Type get_type() const;//получать тип
		float get_a() const;//получать а
		float get_b() const;
		float get_c() const;
		float get_x() const;
		float compute_value() const;//вычислить значение
		float compute_derivative() const;//вычислить производную
		float compute_antiderivative() const;


	};

	//надо подумать

	//надо найти минимальны элемент в функции проихводной с данным аргументом
	class Container {
	public:
		static const int N = 10;
	private:
		Function listf[N];
		int corsize = 0;
	public:
		Container();
		Container(Function s[], int size);
		int get_size() const;
		Function& operator[](int n);
		Function operator[](int n) const;
		void appendel(int n, Function a);
		void dellel(int n);
		Function find_min_derivative();
	};
}
