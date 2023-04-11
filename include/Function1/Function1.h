#pragma once

namespace function {

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

	public:
		Function();
		Function(Type type, float a, float b);
		Function(Type type, float c);
		Type get_type() const;//�������� ���
		float get_a() const;//�������� �
		float get_b() const;
		float get_c() const;
		float compute_value(float x) const;//��������� ��������
		Function compute_derivative() const;//��������� �����������
		Function compute_antiderivative() const;


	};


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
